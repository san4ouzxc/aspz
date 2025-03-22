FROM debian:latest

RUN apt update && apt install -y gcc

COPY 3.c /app/3.c
WORKDIR /app

RUN gcc 3.c -o 3

CMD ["/bin/bash", "-c", "\
    ulimit -f 15; \
    echo '[*] Starting dice roll simulation...'; \
    ./3"]
