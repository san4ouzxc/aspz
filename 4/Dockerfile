FROM debian:latest

RUN apt update && apt install -y gcc

COPY 4.c /app/4.c
WORKDIR /app

RUN gcc 4.c -o 4

CMD ["/bin/bash", "-c", "\
    echo '$ prlimit --cpu=1:2 ./4'; prlimit --cpu=1:2 ./4"]
