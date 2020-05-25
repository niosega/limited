#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SIZE 1000000000
int main() {
    // 10 Go.
    char* a = (char*) malloc(SIZE);
    for (int i = 0; i < SIZE; i++) {
        a[i] = 0;
    }

    sleep(10000000);
    return 0;
}