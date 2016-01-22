#include <stdio.h>

main() {
   char str[] = "Hello World!";

   printf("*  %d\n", strlen_2(str));
   printf("[] %d\n", strlen_1(str));
   printf("p  %d\n", strlen_3(str));
   return 0;
}

int strlen_2(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int strlen_1(char *s) {
    int n;

    for (n = 0; s[n] != '\0'; n++)
        ;
    return n;
}

int strlen_3(char *s) {
    char *p = s;

    while (*p != '\0')
        p++;
    return p - s;
}
