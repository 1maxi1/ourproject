FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    build-essential

WORKDIR /root/
RUN mkdir server
WORKDIR /root/server/
COPY . .

RUN qmake server.pro && make

ENTRYPOINT ["./server"]