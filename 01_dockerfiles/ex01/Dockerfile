FROM debian:jessie

MAINTAINER aheil

ENV TS_VERSION LATEST
ENV LANG C.UTF-8

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get -y install bzip2 wget ca-certificates \
    && rm -rf /var/lib/apt/lists/* \
    && useradd -M -s /bin/false --uid 1000 teamspeak3 \
    && mkdir /data \
    && chown teamspeak3:teamspeak3 /data

COPY get-version.sh /get-version
COPY start-teamspeak3.sh /start-teamspeak3

EXPOSE 9987/udp 10011 30033

USER teamspeak3
VOLUME /data
WORKDIR /data
ENTRYPOINT ["/start-teamspeak3"]

# #docker build -t ts3 .
# #docker run -d --name ts3 -p 9987:9987/udp -p 30033:30033/tcp -p 10011:10011/tcp ts3
# FROM debian
# EXPOSE 9987/udp
# EXPOSE 10011/tcp
# EXPOSE 30033/tcp
# ADD http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2 /opt/
# RUN useradd teamspeak && mkdir -p /opt/teamspeak3-server_linux_amd64/data && chown teamspeak:teamspeak /opt/teamspeak3-server_linux_amd64/data
# VOLUME /opt/teamspeak3-server_linux_amd64/data
# USER teamspeak
# CMD /opt/teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh start

# https://github.com/GlThibault/Docker/blob/master/01_dockerfiles/ex01/Dockerfile