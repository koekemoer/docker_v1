FROM debian
RUN apt-get update -y\
	&& apt-get install git -y\
	&& apt-get install make -y\
	&& apt-get install gcc -y\
	&& apt-get install vim -y

COPY . /opt/
CMD ["/bin/bash"]
WORKDIR /opt/minishell
RUN make re

#docker build -t c .
#docker run -it --rm --name ctest c
