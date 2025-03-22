FROM debian:latest

RUN apt-get update && apt-get install -y gcc procps

COPY 7.c /usr/src/7.c

WORKDIR /usr/src

RUN gcc -o 7 7.c

CMD echo '$ ulimit -s 1024 && ./7' && ulimit -s 1024 && ./7
# Для середнього стека:
# CMD echo '$ ulimit -s 8192 && ./7' && ulimit -s 8192 && ./7
# Для безмежного стека:
# CMD echo '$ ulimit -s unlimited && ./7' && ulimit -s unlimited && ./7
