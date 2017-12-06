FROM debian
RUN apt-get update -y\
	&& apt-get install telnet -y\
	&& apt-get install libncurses5-dev -y\
	&& apt-get install libncursesw5-dev -y

CMD ["telnet", "towel.blinkenlights.nl"]

#docker build -t sw .
#docker run -it --rm --name swtest sw