#include <stdio.h>
#include <string.h>

int atoi(char s[]);
void itoa(int n, char s[]);
void reverse(char s[]);

main() {
    int c, i, nwhite, nother, ndigit[10];
    char j, line[1000];

    j = nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while( (c = getchar()) != EOF) {
        line[j++] = c;

        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                ndigit[c - '0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }

    }
    printf("line: %s", line);
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

    int num = atoi(line);
    printf("integer: %d\n", num);
    //reverse(line);
    //printf("reverse line: %s", line);
    itoa(num, line);
    printf("string: %s\n", line);
    return 0;
}

int atoi(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = n * 10 + (s[i] - '0');
    return sign * n;
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i]; s[i] = s[j]; s[j] = c;
    
    }
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n = n / 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
