FROM alpine:3.5

# Install system utils & Gogs runtime dependencies
ADD https://github.com/tianon/gosu/releases/download/1.9/gosu-amd64 /usr/sbin/gosu
RUN chmod +x /usr/sbin/gosu \
  && echo http://dl-2.alpinelinux.org/alpine/edge/community/ >> /etc/apk/repositories \
  && apk --no-cache --no-progress add \
    bash \
    ca-certificates \
    curl \
    git \
    linux-pam \
    openssh \
    s6 \
    shadow \
    socat \
    tzdata

ENV GOGS_CUSTOM /data/gogs

# Configure LibC Name Service
COPY docker/nsswitch.conf /etc/nsswitch.conf
COPY docker /app/gogs/docker
COPY templates /app/gogs/templates
COPY public /app/gogs/public

WORKDIR /app/gogs/build
COPY . .

RUN    ./docker/build-go.sh \
    && ./docker/build.sh \
    && ./docker/finalize.sh

# Configure Docker Container
VOLUME ["/data"]
EXPOSE 22 3000
ENTRYPOINT ["/app/gogs/docker/start.sh"]
CMD ["/bin/s6-svscan", "/app/gogs/docker/s6/"]

# #docker build -t gogs .
# #docker run -d --name Gogs -p 3000:3000 gogs
# FROM golang
# EXPOSE 3000
# RUN adduser --disabled-login --gecos 'Gogs' git
# RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install mysql-server -y && \
# service mysql start && mysql -uroot -e "create database gogs"
# USER git
# RUN mkdir -p $GOPATH/src/github.com/gogits && cd $GOPATH/src/github.com/gogits && git clone --depth=1 -b develop https://github.com/gogits/gogs && cd gogs && go build
# USER root
# CMD service mysql start && su git -c "$GOPATH/src/github.com/gogits/gogs/gogs web"

# https://github.com/GlThibault/Docker/blob/master/01_dockerfiles/ex03/Dockerfile