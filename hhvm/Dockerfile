# Use phusion/baseimage as base image. To make your builds
# reproducible, make sure you lock down to a specific version, not
# to `latest`! See
# https://github.com/phusion/baseimage-docker/blob/master/Changelog.md
# for a list of version numbers.
FROM phusion/baseimage:0.9.9

# Set correct environment variables.
ENV HOME /root

# Regenerate SSH host keys. baseimage-docker does not contain any, so you
# have to do that yourself. You may also comment out this instruction; the
# init system will auto-generate one during boot.
RUN /etc/my_init.d/00_regen_ssh_host_keys.sh

# Use baseimage-docker's init system.
ENTRYPOINT ["/sbin/my_init"]

# install add-apt-repository
RUN sudo apt-get update
RUN sudo apt-get install -y software-properties-common python-software-properties

# we'll need wget to fetch the key...
RUN sudo apt-get install -y wget

# install hhvm
RUN sudo add-apt-repository ppa:mapnik/boost
RUN wget -O - http://dl.hhvm.com/conf/hhvm.gpg.key | sudo apt-key add -
RUN echo deb http://dl.hhvm.com/ubuntu precise main | sudo tee /etc/apt/sources.list.d/hhvm.list
RUN sudo apt-get update
RUN sudo apt-get install -y hhvm-nightly

# install nginx
RUN sudo apt-get install -y nginx
RUN echo "daemon off;" >> /etc/nginx/nginx.conf

RUN mkdir /etc/service/nginx
ADD ./nginx.sh /etc/service/nginx/run

# set up php ini
ADD ./php.ini /etc/hhvm/php.ini

# set up hhvm config
ADD ./server.hdf /etc/hhvm/server.hdf

RUN mkdir /etc/service/hhvm
ADD ./hhvm.sh /etc/service/hhvm/run

# set up nginx default site
ADD ./nginx-default /etc/nginx/sites-available/default

# create a directory with a sample index.php file
# RUN sudo mkdir -p /mnt/hhvm
# ADD ./app/index.php /mnt/hhvm/index.php

RUN sudo /usr/share/hhvm/install_fastcgi.sh

# Clean up APT when done.
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# expose port 80
EXPOSE 80