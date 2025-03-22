#include <stdio.h>
#include <stdlib.h>

void recursive_function(int depth) {
    char buffer[10000];
    printf("Recursion depth: %d\n", depth);

    recursive_function(depth + 1);
}

int main() {
    recursive_function(1);
    return 0;
}
