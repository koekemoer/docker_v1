# FROM ruby

# RUN apt-get update -y && apt-get upgrade -y
# RUN gem install rails bundler
# RUN apt-get install nodejs -y
# RUN apt-get autoclean -y && apt-get clean -y

# ONBUILD COPY . ~/.brew/opt/app

# ONBUILD WORKDIR ~/.brew/opt/app

# ONBUILD RUN bundle install
# ONBUILD RUN rails db:migrate
# ONBUILD RUN rails db:seed

# # FROM        ft-rails:5.0.2-on-build
# CMD         ["rails", "s", "-b", "0.0.0.0"]

FROM ruby
EXPOSE 3000
WORKDIR /opt/app
RUN apt-get update && apt-get install nodejs -y && gem install rails -v 5.0.2 && \
    rails new server && cd server && bundle && \
    rake db:migrate && rake db:seed