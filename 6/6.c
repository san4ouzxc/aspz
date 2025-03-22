#include <stdio.h>

void recursive_function(int count) {
    printf("Recursion count: %d\n", count);
    recursive_function(count + 1);  // Рекурсивний виклик
}

int main() {
    recursive_function(1);
    return 0;
}
