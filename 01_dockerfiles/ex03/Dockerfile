FROM golang
EXPOSE 3000
RUN adduser --disabled-login --gecos 'Gogs' git
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install mysql-server -y && \
service mysql start && mysql -uroot -e "create database gogs"
USER git
RUN mkdir -p $GOPATH/src/github.com/gogits && cd $GOPATH/src/github.com/gogits && git clone --depth=1 -b develop https://github.com/gogits/gogs && cd gogs && go build
USER root
CMD service mysql start && su git -c "$GOPATH/src/github.com/gogits/gogs/gogs web"