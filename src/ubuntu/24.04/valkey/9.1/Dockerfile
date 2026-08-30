FROM phusion/baseimage:noble-1.0.3

LABEL maintainer="charescape@outlook.com"

ENV TZ="Asia/Shanghai"
ENV VALKEY_VERSION="9.1.1"
ENV VALKEY_HASH="7d7232acd1b8a49b4e05d07a00b3ca8c801ae06ab633ca6a3423bc5f385ab7ee"
ENV KILL_PROCESS_TIMEOUT=60
ENV KILL_ALL_PROCESSES_TIMEOUT=60
ENV PATH="/usr/local/valkey/bin:${PATH}"

COPY src/ubuntu/24.04/valkey/9.1/chown-valkey.sh  /etc/my_init.d/
COPY src/ubuntu/24.04/valkey/9.1/valkey.conf  /usr/local/src/
COPY src/ubuntu/24.04/valkey/9.1/valkey.run  /usr/local/src/
COPY src/ubuntu/24.04/valkey/9.1/jemalloc-configure-opts.sh  /usr/local/src/

SHELL ["/bin/bash", "-c"]

RUN set -eux \
&& set -o pipefail \
&& export DEBIAN_FRONTEND=noninteractive \
\
&& free -m            \
\
&& apt -y update            \
&& apt -yq -o Dpkg::Options::="--force-confold" upgrade \
&& apt -y autoremove        \
\
\
&& mkdir -p /wwwdata/valkey/data \
&& mkdir -p /wwwdata/valkey/run \
&& mkdir -p /wwwdata/misc \
&& chown -R www-data:www-data /wwwdata \
\
&& apt -yq --no-install-recommends install tzdata \
build-essential                 \
pkg-config                      \
ca-certificates                 \
wget                            \
dpkg-dev                        \
libssl-dev                      \
\
\
&& chmod +x /etc/my_init.d/chown-valkey.sh \
\
&& cd /usr/local/src \
\
&& wget --no-verbose -O valkey-${VALKEY_VERSION}.tar.gz https://github.com/valkey-io/valkey/archive/refs/tags/${VALKEY_VERSION}.tar.gz \
&& echo "${VALKEY_HASH} *valkey-${VALKEY_VERSION}.tar.gz" | sha256sum --check \
\
&& tar -zxf valkey-${VALKEY_VERSION}.tar.gz \
\
\
&& cd /usr/local/src/valkey-${VALKEY_VERSION} \
&& JEMALLOC_CONFIGURE_OPTS="$(sh /usr/local/src/jemalloc-configure-opts.sh)" \
&& make -j$(nproc --all) BUILD_TLS=yes USE_SYSTEMD=no PREFIX=/usr/local/valkey \
     JEMALLOC_CONFIGURE_OPTS="${JEMALLOC_CONFIGURE_OPTS}" \
&& sleep 3s \
&& make BUILD_TLS=yes USE_SYSTEMD=no PREFIX=/usr/local/valkey \
     JEMALLOC_CONFIGURE_OPTS="${JEMALLOC_CONFIGURE_OPTS}" install \
\
\
&& cd /usr/local/src \
&& cp ./valkey.conf /etc/valkey.conf \
&& chown www-data:www-data /etc/valkey.conf \
&& chown -R www-data:www-data /usr/local/valkey \
&& chown -R www-data:www-data /wwwdata \
\
&& /usr/local/valkey/bin/valkey-server --version \
&& /usr/local/valkey/bin/valkey-cli --version \
\
\
&& chown -R www-data:www-data /usr/local/valkey \
&& chown -R www-data:www-data /wwwdata \
&& chown www-data:www-data /etc/valkey.conf \
\
&& mkdir -p /etc/service/valkey \
&& cp /usr/local/src/valkey.run /etc/service/valkey/run \
&& chmod +x /etc/service/valkey/run \
\
&& apt -y autoremove \
&& apt -y clean \
&& rm -rf /var/lib/apt/lists/* \
\
&& rm -rf  /var/cache/fontconfig/* \
&& rm -rf  /var/cache/apt/archives/*.deb \
&& rm -rf  /usr/share/doc/* \
&& rm -rf  /usr/share/man/* \
\
&& rm -rf /tmp/* \
&& rm -rf /var/tmp/* \
\
&& rm -rf  ~/.cache/* \
\
&& du -h --max-depth=2 /usr/local/valkey \
&& du -h --max-depth=2 /wwwdata/valkey \
&& rm -rf /usr/local/src/*

EXPOSE 6379

CMD ["/sbin/my_init"]
