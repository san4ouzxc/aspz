#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/resource.h>

#define BUFFER_SIZE 1024

void set_file_size_limit() {
    struct rlimit limit;
    limit.rlim_cur = 4;  // Установим лимит в 4 байта (можно менять)
    limit.rlim_max = 4;
    if (setrlimit(RLIMIT_FSIZE, &limit) != 0) {
        perror("Failed to set file size limit");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Program need two arguments\n");
        return EXIT_FAILURE;
    }

    const char *src_file = argv[1];
    const char *dst_file = argv[2];

    int src_fd = open(src_file, O_RDONLY);
    if (src_fd < 0) {
        fprintf(stderr, "Cannot open file %s for reading\n", src_file);
        return EXIT_FAILURE;
    }

    set_file_size_limit();

    int dst_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd < 0) {
        fprintf(stderr, "Cannot open file %s for writing\n", dst_file);
        close(src_fd);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written, total_written = 0;

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Write error");
            close(src_fd);
            close(dst_fd);
            return EXIT_FAILURE;
        }
        total_written += bytes_written;

        struct rlimit limit;
        getrlimit(RLIMIT_FSIZE, &limit);
        if (total_written >= limit.rlim_cur) {
            fprintf(stderr, "File size limit exceeded! Stopping copying.\n");
            break;
        }
    }

    close(src_fd);
    close(dst_fd);

    printf("File copy completed. Total bytes written: %ld\n", total_written);
    return EXIT_SUCCESS;
}
