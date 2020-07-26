FROM alpine:latest
MAINTAINER rathodrowa@myvuw.ac.nz

RUN mkdir /opt/workspace
WORKDIR /opt/workspace
COPY software /opt/workspace

RUN ls

RUN chmod +x software_runner.sh

RUN apt-get update -qq && apt-get install -qq -y --no-install-recommends wget unzip git make \
 srecord bc xz-utils gcc python curl python-pip python-dev build-essential \
 && python -m pip install --upgrade pip setuptools

RUN pip install -U platformio

RUN echo "This is a message from the Dockerfile"
