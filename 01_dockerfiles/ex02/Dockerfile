FROM ruby

RUN apt-get update -y && apt-get upgrade -y
RUN gem install rails
RUN apt-get install nodejs -y
RUN apt-get autoclean -y && apt-get clean -y

ONBUILD COPY . /opt/app

ONBUILD WORKDIR /opt/app

ONBUILD RUN bundle install
ONBUILD RUN rails db:migrate
ONBUILD RUN rails db:seed