#include <stdio.h>
#include <time.h>
#include "vector.h"

#define MAX_DURATION 20
#define PRIMES_PER_ROW 10

int main() {
    int newline = 0;

    VECTOR_INIT(primes);
    VECTOR_ADD(primes, (void *) 2);

    time_t start = time(NULL);

    for (int i = 3;; i++) {
        short isPrime = 1;
        for (int j = 0; j < VECTOR_TOTAL(primes); j++) {
            if (i % VECTOR_GET(primes, int, j) == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 0) continue;

        VECTOR_ADD(primes, i);
        printf("%d, ", i);
        newline = ++newline % PRIMES_PER_ROW;
        if (newline == 0) {
            printf("\n");
        }

        if (time(NULL) - start > MAX_DURATION) {
            printf("found %d primes\n", VECTOR_TOTAL(primes));
#ifdef __clang_major__
            printf("version: clang %d.%d\n", __clang_major__, __clang_minor__);
#endif
#ifdef __GNUC__
            printf("version: gcc %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif
            VECTOR_FREE(primes);
            return 0;
        }
    }
}