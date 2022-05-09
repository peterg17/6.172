# Dockerfile to create devenv for 6.172 code
FROM ubuntu:xenial

RUN apt-get update && apt-get install -y \
    curl \
    unzip \
    make \
    software-properties-common \
    build-essential \
    clang \
    x11-apps \
    libx11-dev \
    xorg-dev \
    xterm \
    emacs # optional - can replace with editor of choice

RUN add-apt-repository -y ppa:wsmoses/tapir-toolchain \
    &&  apt-get update \
    &&  apt-get install -y tapirclang-5.0 libcilkrts5
