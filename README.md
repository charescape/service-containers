Release
-------------

New images use this layout:

```
src/<os>/<os_ver>/<service>/<service_ver>/Dockerfile
```

From the repo root:

```
npm run release -- ubuntu/24.04/mariadb/12.3
```

That runs [`scripts/release.mjs`](scripts/release.mjs): it checks the Dockerfile exists, then uses `np` (`--yolo --no-publish --no-release-draft`) to bump, commit, tag, and push. The commit message is:

```
release ubuntu/24.04/mariadb/12.3 v0.1.0
```

Each run uses `np minor` (`v0.1.0`, `v0.2.0`, …). Those git tags are the repo version only.

[`.github/workflows/release.yml`](.github/workflows/release.yml) builds `src/ubuntu/24.04/mariadb/12.3/Dockerfile` and pushes `ghcr.io/<owner>/docker-images:ubuntu-24.04-mariadb-12.3` and `<DOCHUB_USERNAME>/docker-images:ubuntu-24.04-mariadb-12.3`. Running the same path again **overwrites** that tag.

The path after `release` must be exactly four segments, followed by `v` plus a semver. Old flat directories (`src/ubuntu24-php84-mysql84`, `src/ubuntu16-mariadb55`) still go through [`.github/workflows/ci.yml`](.github/workflows/ci.yml).
