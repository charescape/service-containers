
alias wwwpull='sudo -H -u www-data bash -c "git pull"'
alias wwwstatus='sudo -H -u www-data bash -c "git status"'
alias wwwdiff='sudo -H -u www-data bash -c "git diff"'
alias wwwlog='sudo -H -u www-data bash -c "git log"'
alias wwwecho='echo "sudo -H -u www-data bash -c"'
alias wwwchown='chown -R www-data:www-data'
alias cathistory='cat ~/.bash_history'


# 当前会话保存的历史命令数量
export HISTSIZE=50000

# .bash_history 最大行数
export HISTFILESIZE=50000

# 记录命令执行时间
export HISTTIMEFORMAT="%F %T "

# 忽略重复命令
export HISTCONTROL=ignoredups


export PATH="$PATH:/usr/local/openresty/nginx/sbin"
export PATH="$PATH:/usr/local/php/bin:/usr/local/php/sbin"
export PATH="$PATH:/usr/local/mysql/bin"
export PATH="$PATH:/usr/local/mysql/support-files"
