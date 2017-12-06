FROM debian
RUN apt-get update -y\
	&& apt-get upgrade -y\
	&& apt-get install git -y\
	&& apt-get install python2.7 -y\
	&& apt-get install python-pip -y\
	&& pip install numpy

CMD ["python2"]

#docker build -t python2 .
#docker run -it --rm --name python2test python2