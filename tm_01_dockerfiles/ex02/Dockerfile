FROM ruby
EXPOSE 3000
RUN apt-get update\
	&& apt-get install nodejs -y\
	&& apt-get install build-essential -y\
	&& gem install rails -v 5.0.2

WORKDIR /opt/app

RUN rails new ex02\
	&& cd ex02 && bundle\
	&& rake db:migrate && rake db:seed

#docker build -t ft-rails:5.0.2-on-build .
#docker build -t ex02 -f test_Dockerfile .
#docker run -p 3000:3000 --name ex02test ex02