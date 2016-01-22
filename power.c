#include <stdio.h>

int power (int m, int n);

main() {
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %4d %6d\n", i, power2(2, i), power2(-3, i));
    return 0;
}

int power(int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

int power2(int base, int n) {
    int p;

    for(p = 1; n > 0; --n)
        p = p * base;
    return p;
}
