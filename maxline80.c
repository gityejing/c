#include <stdio.h>
#define MAXLINE 1000
#define MORETHAN 80

int get_line(char line[], int lim);
void copy(char to[], char from[]);

main() {
    int len;
    int max;

    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%d: %s", len, line);

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("Longest is %d charcaters:\n%s", max, longest);
    printf("\n");
    return 0;
}

int get_line(char s[], int lim) {
    int c, i, j;

    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1)
            s[j++] = c;
        if (c == '\n') {
            if (i <= lim - 1)
                s[j++] = c;
            ++i;
        }
    }
    s[j] = '\0';
    printf("%d", i);
    return i;
}

void copy(char to[], char from[]) {
   int i; 

   while ((to[i] = from[i]) != '\0')
       ++i;
}
