FROM debian
RUN apt-get update -y\
	&& apt-get upgrade -y\
	&& apt-get install git -y\
	&& apt-get install python3-pip -y\
	&& pip3 install numpy

CMD ["python3"]

#docker build -t python3 .
#docker run -it --rm --name python3test python3