FROM debian:latest

WORKDIR /app

RUN apt update && apt install -y gcc && rm -rf /var/lib/apt/lists/*

COPY file_copy.c /app/file_copy.c

RUN gcc file_copy.c -o file_copy

COPY source.txt /app/source.txt

CMD ["/bin/bash", "-c", "\
    echo '$ ./file_copy source.txt destination.txt'; \
    ulimit -f 2 && \
    ./file_copy source.txt destination.txt; \
    echo 'File copy completed. Destination file content:'; \
    cat destination.txt"]
