#include <stdio.h>

main(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%d%s", argv[i], (i < argc-1) ? " " : "");
    printf("\n");
    return 0;
}
