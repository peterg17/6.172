FROM ubuntu:xenial


# docker run -td <image id>


RUN apt-get update
RUN apt-get -y install curl
RUN apt-get -y install unzip
RUN curl -L -o project2.zip https://ocw.mit.edu/courses/6-172-performance-engineering-of-software-systems-fall-2018/e73f8fc30a609509b847f708815a72c0_MIT6_172F18-project2.zip
RUN unzip project2.zip

RUN cd MIT6_172F18-project2
RUN apt-get install -y make
RUN apt-get install -y emacs # optional - can replace with editor of choice
RUN apt-get install -y software-properties-common
RUN add-apt-repository -y ppa:wsmoses/tapir-toolchain
RUN apt-get update
RUN apt-get install -y tapirclang-5.0 libcilkrts5
RUN apt-get install -y build-essential clang
RUN apt-get install -y x11-apps
RUN apt-get install -y libx11-dev
RUN apt-get install -y xorg-dev xterm
