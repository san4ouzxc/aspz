#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/resource.h>

#define FILE_NAME "dice_rolls.txt"

void handle_sigxfsz(int signum) {
    printf("\n[!] File size limit reached. Stopping write operation.\n");
    printf("\n=== File content: ===\n");
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    }
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGXFSZ, handle_sigxfsz);

    struct rlimit lim = {15, 15};
    if (setrlimit(RLIMIT_FSIZE, &lim) != 0) {
        perror("Failed to set file size limit");
        return 1;
    }

    printf("[*] File size limit set to %ld bytes\n", (long)lim.rlim_cur);

    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        perror("Cannot open file");
        return 1;
    }

    srand(time(NULL));

    while (1) {
        int roll = rand() % 6 + 1;
        printf("Rolling: %d\n", roll);

        if (fprintf(file, "%d\n", roll) < 0) {
            perror("[!] Error writing to file");
            break;
        }
        fflush(file);
    }

    fclose(file);

    printf("\n[!] File content after limit reached:\n");
    char buffer[256];
    file = fopen(FILE_NAME, "r");
    if (file) {
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        perror("Error opening file for reading");
    }

    return 0;
}
