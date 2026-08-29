import { existsSync, readFileSync } from 'node:fs'
import { spawnSync } from 'node:child_process'
import path from 'node:path'
import { fileURLToPath } from 'node:url'

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..')
const dir = process.argv[2] ?? ''

function fail(message) {
  console.error(message)
  process.exit(1)
}

function run(command, args) {
  const result = spawnSync(command, args, {
    cwd: root,
    stdio: 'inherit',
    shell: true,
  })
  if (result.status !== 0) {
    process.exit(result.status ?? 1)
  }
}

if (!/^[a-zA-Z0-9._-]+\/[a-zA-Z0-9._-]+\/[a-zA-Z0-9._-]+\/[a-zA-Z0-9._-]+$/.test(dir)) {
  fail('usage: npm run release -- <os>/<os_ver>/<service>/<service_ver>')
}

if (dir.split('/').some((segment) => segment === '.' || segment === '..')) {
  fail(`invalid path segment in ${dir}`)
}

const dockerfile = path.join(root, 'src', ...dir.split('/'), 'Dockerfile')
if (!existsSync(dockerfile)) {
  fail(`missing src/${dir}/Dockerfile`)
}

const pkg = JSON.parse(readFileSync(path.join(root, 'package.json'), 'utf8'))
const major = Number(/^(\d+)/.exec(pkg.version ?? '0')?.[1] ?? 0)
const bump = major < 1 ? '1.0.0' : 'patch'

run('git', ['pull'])
run('npm', [
  'exec',
  '--',
  'np',
  bump,
  '--yolo',
  '--no-publish',
  '--no-release-draft',
  `--message="release ${dir} v%s"`,
])
