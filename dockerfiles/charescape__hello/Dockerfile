FROM phusion/baseimage:noble-1.0.2

COPY ./dockerfiles/charescape__hello/helloworld  /etc/my_init.d/

RUN set -eux \
&& chmod +x /etc/my_init.d/helloworld \
&& /etc/my_init.d/helloworld

CMD ["/sbin/my_init"]
