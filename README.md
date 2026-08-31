Release
-------------

New images use this layout:

```
src/<os>/<os_ver>/<service>/<service_ver>/Dockerfile
src/<os>/<os_ver>/<service>/<service_ver>/VERSION
```

`VERSION` is two-part (`1.0`, `1.1`, `2.0`) and is independent per image. From the repo root:

```
npm run major -- ubuntu/24.04/mariadb/12.3
npm run patch -- ubuntu/24.04/mariadb/12.3
```

That runs [`scripts/release.mjs`](scripts/release.mjs): it checks the Dockerfile exists, bumps the image `VERSION` (`patch` is `1.0` → `1.1`; `major` is `1.1` → `2.0`), then uses `np` (`--yolo --no-publish --no-release-draft`) to bump `package.json`, commit, tag, and push. The commit message uses the **image** version:

```
release ubuntu/24.04/mariadb/12.3 v1.1
```

`np` still always runs `minor` on `package.json`. Those git tags (`v1.11.0`, …) are the repo version only.

[`.github/workflows/release.yml`](.github/workflows/release.yml) builds `src/ubuntu/24.04/mariadb/12.3/Dockerfile` and pushes `ghcr.io/<owner>/docker-images:ubuntu-24.04-mariadb-12.3-v1.1` and `<DOCHUB_USERNAME>/docker-images:ubuntu-24.04-mariadb-12.3-v1.1`. Each release is a new tag.

The path after `release` in the commit message must be exactly four segments, followed by `v` plus `X.Y`. Old flat directories (`src/ubuntu24-php84-mysql84`, `src/ubuntu16-mariadb55`) still go through [`.github/workflows/ci.yml`](.github/workflows/ci.yml).
