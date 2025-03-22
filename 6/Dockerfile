FROM debian:latest

RUN apt-get update && apt-get install -y gcc procps

COPY 6.c /usr/src/6.c

WORKDIR /usr/src

RUN gcc -o 6 6.c

CMD echo '$ prlimit --stack=8192 && ./6' && prlimit --stack=8192 && ./6
