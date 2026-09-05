#!/bin/sh

# Load MARIADB_BACKUP_* from /wwwdata/misc/container.conf (KEY=VALUE).
# Source this file. Does not source the conf file.

CONTAINER_CONF="${CONTAINER_CONF:-/wwwdata/misc/container.conf}"

MARIADB_BACKUP_ENABLE=0
MARIADB_BACKUP_CRON="0 3 * * *"
MARIADB_BACKUP_KEEP_DAYS=30
MARIADB_BACKUP_DIR=/wwwdata/misc/backup

if [ -f "$CONTAINER_CONF" ]; then
  while IFS= read -r line || [ -n "$line" ]; do
    line=$(printf '%s' "$line" | tr -d '\r')
    trimmed=$(printf '%s' "$line" | sed 's/^[[:space:]]*//')
    case "$trimmed" in
      '' | \#*) continue ;;
    esac
    case "$trimmed" in
      *=*) ;;
      *) continue ;;
    esac
    key=$(printf '%s' "${trimmed%%=*}" | sed 's/[[:space:]]*$//')
    val="${trimmed#*=}"
    case "$key" in
      MARIADB_BACKUP_ENABLE | MARIADB_BACKUP_CRON | MARIADB_BACKUP_KEEP_DAYS | MARIADB_BACKUP_DIR) ;;
      *) continue ;;
    esac
    case "$val" in
      \"*\")
        val="${val#\"}"
        val="${val%\"}"
        ;;
      \'*\')
        val="${val#\'}"
        val="${val%\'}"
        ;;
    esac
    case "$key" in
      MARIADB_BACKUP_ENABLE) MARIADB_BACKUP_ENABLE="$val" ;;
      MARIADB_BACKUP_CRON) MARIADB_BACKUP_CRON="$val" ;;
      MARIADB_BACKUP_KEEP_DAYS) MARIADB_BACKUP_KEEP_DAYS="$val" ;;
      MARIADB_BACKUP_DIR) MARIADB_BACKUP_DIR="$val" ;;
    esac
  done <"$CONTAINER_CONF"
fi

unset line trimmed key val
