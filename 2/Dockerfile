FROM debian:latest

RUN apt update && apt install -y linux-perf \
    && rm -rf /var/lib/apt/lists/*

CMD ["/bin/bash", "-c", "\
    echo '$ perf --version'; perf --version; \
    echo '$ ls'; perf stat ls;"]