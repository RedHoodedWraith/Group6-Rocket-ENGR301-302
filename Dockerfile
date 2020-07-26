FROM ubuntu
MAINTAINER rathodrowa@myvuw.ac.nz

RUN mkdir /opt/workspace
WORKDIR /opt/workspace
COPY software /opt/workspace

RUN ls

RUN chmod +x software_runner.sh

RUN apt update && apt install wget unzip git make \
srecord bc xz-utils gcc python curl python-pip python-dev build-essential

RUN python -m pip install --upgrade pip setuptools

RUN pip install -U platformio

RUN echo "This is a message from the Dockerfile"
