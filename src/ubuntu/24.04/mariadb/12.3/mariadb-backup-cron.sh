#!/bin/sh

set -eu

# Install or remove /etc/cron.d/mariadb-backup from docker -e / container env.
# my_init runs this after chown-mysql.sh (lexicographic order).

if [ -f /etc/container_environment.sh ]; then
  # shellcheck disable=SC1091
  . /etc/container_environment.sh
fi

CRON_FILE="/etc/cron.d/mariadb-backup"
ENABLE="${MARIADB_BACKUP_ENABLE:-1}"
SCHEDULE="${MARIADB_BACKUP_CRON:-0 3 * * *}"

enabled=0
case "$ENABLE" in
  1|true|TRUE|yes|YES|on|ON) enabled=1 ;;
esac

if [ "$enabled" -eq 1 ]; then
  umask 022
  cat > "$CRON_FILE" <<EOF
MAILTO=""
SHELL=/bin/bash
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
${SCHEDULE} root /usr/local/sbin/mariadb-backup.sh >>/proc/1/fd/1 2>>/proc/1/fd/2
EOF
  chmod 644 "$CRON_FILE"
else
  rm -f "$CRON_FILE"
fi
