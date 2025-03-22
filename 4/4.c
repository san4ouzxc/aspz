#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

void handle_sigxcpu(int signum) {
    printf("\n[!] CPU time limit exceeded! Stopping execution.\n");
    exit(EXIT_FAILURE);
}

void generate_numbers(int *numbers, int count, int max_value) {
    int used[max_value + 1];
    for (int i = 0; i <= max_value; i++) used[i] = 0;

    for (int i = 0; i < count; i++) {
        int num;
        do {
            num = rand() % max_value + 1;
        } while (used[num]); 

        numbers[i] = num;
        used[num] = 1;
    }
}

int main() {
    signal(SIGXCPU, handle_sigxcpu); 

    srand(time(NULL));

    int lottery_49[7];
    int lottery_36[6];

    printf("[*] Generating lottery numbers...\n");

    generate_numbers(lottery_49, 7, 49);
    generate_numbers(lottery_36, 6, 36);

    printf("Winning numbers (7 from 49): ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", lottery_49[i]);
    }
    printf("\n");

    printf("Winning numbers (6 from 36): ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", lottery_36[i]);
    }
    printf("\n");

    printf("Entering infinite loop to trigger CPU limit...\n");
    while (1) {
    }

    return 0;
}
