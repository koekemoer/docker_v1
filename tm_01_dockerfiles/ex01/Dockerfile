FROM debian
ADD http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2 /opt/
EXPOSE 9987/udp
EXPOSE 10011/tcp
EXPOSE 30033/tcp
RUN apt-get update -y\
	&& apt-get install bzip2 -y\
	&& adduser --disabled-password --gecos "" teamspeak\
	&& tar -jxf /opt/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2 -C /opt/\
	&& chown teamspeak:teamspeak /opt/teamspeak3-server_linux_amd64/ && chmod 0770 /opt/teamspeak3-server_linux_amd64/
USER teamspeak
CMD ["/opt/teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]

#docker build -t ex01 .
#docker run -t --name ex01test -p 9987:9987/udp -p 30033:30033/tcp -p 10011:10011/tcp ex01