FROM alpine

RUN apt-get update -qq && apt-get install -qq -y --no-install-recommends wget unzip git make \
 srecord bc xz-utils gcc python curl python-pip python-dev build-essential \
 && python -m pip install --upgrade pip setuptools

RUN pip install -U platformio
