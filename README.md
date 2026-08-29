Release
-------------

New images use this layout:

```
src/<os>/<os_ver>/<service>/<service_ver>/Dockerfile
```

Commit and push a message that contains:

```
release ubuntu/24.04/mariadb/12.3
```

[`.github/workflows/release.yml`](.github/workflows/release.yml) builds `src/ubuntu/24.04/mariadb/12.3/Dockerfile` and pushes `ghcr.io/<owner>/web:ubuntu-24.04-mariadb-12.3`.

Optional `.rvN` is tag-only (the directory stays without it):

```
release ubuntu/24.04/mariadb/12.3.rv1
```

→ same Dockerfile, tag `ubuntu-24.04-mariadb-12.3.rv1`.

The path after `release` must be exactly four segments. Old flat directories (`src/ubuntu24-php84-mysql84`, `src/ubuntu16-mariadb55`) still go through [`.github/workflows/ci.yml`](.github/workflows/ci.yml).
