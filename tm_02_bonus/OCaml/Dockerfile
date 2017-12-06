FROM debian
RUN apt-get update -y\
	&& apt-get install git -y\
	&& apt-get install ocaml-batteries-included -y\
	&& apt-get install ocamlmakefile -y\
	&& apt-get install opam -y

COPY . /opt/
CMD ["/bin/bash"]
WORKDIR /opt/ex02
RUN make && ./ex02

#docker build -t ocaml .
#docker run -it --rm --name ocamltest ocaml