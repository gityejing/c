#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

main() {
    return 0;
}
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp -n;
    }else
        return 0;
}

void free(char *p) {
    if (p >= allocp && p <= allocbuf + ALLOCSIZE)
        allocp = p;
}
