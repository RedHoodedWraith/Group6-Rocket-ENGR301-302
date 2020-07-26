FROM ubuntu
MAINTAINER rathodrowa@myvuw.ac.nz

RUN mkdir /opt/workspace
WORKDIR /opt/workspace
COPY software /opt/workspace

RUN apt-get update && apt-get install -qq -y --no-install-recommends wget \
unzip git make srecord bc xz-utils gcc python curl python3-pip python-dev \
build-essential
RUN python3 -m pip install --upgrade pip setuptools
RUN pip3 install -U platformio

RUN chmod +x software_runner.py
RUN software_runner.py
