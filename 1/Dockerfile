FROM debian:latest

CMD ["/bin/bash", "-c", "\
    echo '$ ulimit -n'; ulimit -n; \
    echo '$ ulimit -aS | grep \"open files\"'; ulimit -aS | grep 'open files'; \
    echo '$ ulimit -aH | grep \"open files\"'; ulimit -aH | grep 'open files'; \
    echo '$ ulimit -n 3000'; ulimit -n 3000; \
    echo '$ ulimit -aS | grep \"open files\"'; ulimit -aS | grep 'open files'; \
    echo '$ ulimit -aH | grep \"open files\"'; ulimit -aH | grep 'open files'; \
    echo '$ ulimit -n 3001'; ulimit -n 3001; \
    echo '$ ulimit -n 2000'; ulimit -n 2000; \
    echo '$ ulimit -n'; ulimit -n; \
    echo '$ ulimit -aS | grep \"open files\"'; ulimit -aS | grep 'open files'; \
    echo '$ ulimit -aH | grep \"open files\"'; ulimit -aH | grep 'open files'; \
    echo '$ ulimit -n 3000'; ulimit -n 3000;"]
