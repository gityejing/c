#include <stdio.h>

main() {
    int c;

    while ((c = getchar()) != EOF) {
        if ( c == '\n' || c == '\t' || c == ' ')
            printf("\n");
        else
            printf("%c", c);
    }
}
