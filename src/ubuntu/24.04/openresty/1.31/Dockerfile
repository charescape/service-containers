FROM phusion/baseimage:noble-1.0.3

LABEL maintainer="charescape@outlook.com"

ENV TZ="Asia/Shanghai"
ENV OPENRESTY_VERSION="1.31.1.1"
ENV OPENRESTY_HASH="65b78baadd3f0984055de89bf13f4a1932e5bfe9c31932037a134ea2b1a0ce42"
ENV VTS_VERSION="0.2.7"
ENV VTS_HASH="0003bfa57da2106367fdc3f87760910c046e7df5545db73c880fc2b80350b14c"
ENV FLV_VERSION="1.2.14"
ENV FLV_HASH="1021fee0b1022d9d5e4fc823579502fc28b241876406683e3418911a9e855b42"
ENV KILL_PROCESS_TIMEOUT=60
ENV KILL_ALL_PROCESSES_TIMEOUT=60
ENV PATH="/usr/local/openresty/nginx/sbin:${PATH}"

COPY src/ubuntu/24.04/openresty/1.31/chown-openresty.sh  /etc/my_init.d/
COPY src/ubuntu/24.04/openresty/1.31/nginx.conf  /usr/local/src/
COPY src/ubuntu/24.04/openresty/1.31/openresty.run  /usr/local/src/
COPY src/ubuntu/24.04/openresty/1.31/nginxconf/http.d/00-placeholder.conf  /wwwdata/openresty/nginxconf/http.d/
COPY src/ubuntu/24.04/openresty/1.31/nginxconf/rtmp.d/00-placeholder.conf  /wwwdata/openresty/nginxconf/rtmp.d/

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
&& mkdir -p /wwwdata/www \
&& mkdir -p /wwwdata/openresty/logs \
&& mkdir -p /wwwdata/openresty/run \
&& mkdir -p /wwwdata/openresty/nginxconf/ssl \
&& mkdir -p /wwwdata/openresty/nginxconf/http.d \
&& mkdir -p /wwwdata/openresty/nginxconf/rtmp.d \
&& chown -R www-data:www-data /wwwdata \
\
&& apt -yq --no-install-recommends install tzdata \
build-essential                 \
pkg-config                      \
ca-certificates                 \
wget                            \
perl                            \
libssl-dev                      \
libpcre2-dev                    \
zlib1g-dev                      \
\
\
&& chmod +x /etc/my_init.d/chown-openresty.sh \
\
&& cd /usr/local/src \
\
&& wget --no-verbose https://openresty.org/download/openresty-${OPENRESTY_VERSION}.tar.gz \
&& echo "${OPENRESTY_HASH} *openresty-${OPENRESTY_VERSION}.tar.gz" | sha256sum --check \
\
&& wget --no-verbose -O nginx-module-vts-${VTS_VERSION}.tar.gz https://github.com/vozlt/nginx-module-vts/archive/refs/tags/v${VTS_VERSION}.tar.gz \
&& echo "${VTS_HASH} *nginx-module-vts-${VTS_VERSION}.tar.gz" | sha256sum --check \
\
&& wget --no-verbose -O nginx-http-flv-module-${FLV_VERSION}.tar.gz https://github.com/winshining/nginx-http-flv-module/archive/refs/tags/v${FLV_VERSION}.tar.gz \
&& echo "${FLV_HASH} *nginx-http-flv-module-${FLV_VERSION}.tar.gz" | sha256sum --check \
\
&& tar -zxf openresty-${OPENRESTY_VERSION}.tar.gz \
&& tar -zxf nginx-module-vts-${VTS_VERSION}.tar.gz \
&& tar -zxf nginx-http-flv-module-${FLV_VERSION}.tar.gz \
\
\
&& cd /usr/local/src/openresty-${OPENRESTY_VERSION} \
&& ./configure --prefix=/usr/local/openresty \
--with-threads \
--with-file-aio \
--with-http_ssl_module \
--with-http_v2_module \
--with-http_v3_module \
--with-http_realip_module \
--with-http_addition_module \
--with-http_sub_module \
--with-http_gunzip_module \
--with-http_gzip_static_module \
--with-http_auth_request_module \
--with-http_random_index_module \
--with-http_secure_link_module \
--with-http_slice_module \
--with-http_stub_status_module \
--with-http_iconv_module \
--without-mail_pop3_module \
--without-mail_imap_module \
--without-mail_smtp_module \
--with-stream \
--with-stream_ssl_module \
--with-stream_realip_module \
--with-stream_ssl_preread_module \
--with-pcre \
--with-pcre-jit \
--add-dynamic-module=/usr/local/src/nginx-module-vts-${VTS_VERSION} \
--add-dynamic-module=/usr/local/src/nginx-http-flv-module-${FLV_VERSION} \
\
&& make -j$(nproc --all) \
&& sleep 3s \
&& make install \
\
&& cd /usr/local/src \
&& rm -f /usr/local/openresty/nginx/conf/nginx.conf \
&& mv ./nginx.conf /usr/local/openresty/nginx/conf/nginx.conf \
\
&& chown -R www-data:www-data /usr/local/openresty \
&& chown -R www-data:www-data /wwwdata \
\
&& /usr/local/openresty/nginx/sbin/nginx -t \
&& /usr/local/openresty/nginx/sbin/nginx \
&& sleep 3s \
&& /usr/local/openresty/nginx/sbin/nginx -s stop \
\
&& mkdir -p /etc/service/openresty \
&& cp /usr/local/src/openresty.run /etc/service/openresty/run \
&& chmod +x /etc/service/openresty/run \
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
&& du -h --max-depth=2 /usr/local/openresty \
&& du -h --max-depth=2 /wwwdata \
&& rm -rf /usr/local/src/*

EXPOSE 80 443

CMD ["/sbin/my_init"]
