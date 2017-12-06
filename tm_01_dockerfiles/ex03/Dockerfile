FROM debian
ADD https://redirector.gvt1.com/edgedl/go/go1.9.2.linux-amd64.tar.gz .
RUN apt-get update -y\
	&& apt-get install git -y\
	&& adduser --disabled-login --gecos 'Gogs' git\
	&& mkdir home/git/local\
	&& tar -zxf go1.9.2.linux-amd64.tar.gz -C /home/git/local

ENV GOROOT="/home/git/local/go"
ENV GOPATH="/home/git/go"
ENV PATH="$PATH:$GOROOT/bin:$GOPATH/bin"
EXPOSE 3000

USER git
RUN mkdir -p $GOPATH/src/github.com/gogits\
	&& cd $GOPATH/src/github.com/gogits\
	&& git clone --depth=1 -b develop https://github.com/gogits/gogs\
	&& cd gogs\
	&& go build

CMD $GOPATH/src/github.com/gogits/gogs/gogs web

#docker build -t ex03 .
#docker run -it --name ex03test -p 3000:3000 ex03