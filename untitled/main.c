#include <stdio.h>

int main() {
    int i=0, j=0;

    i++ ;
    j++;
    int w = (i++);
    int y = ++i;
    printf("%d %d %d %d", i, j, w, y);
    w = (j++);
    y = (++j);
    printf("%d %d %d %d", i, j, w, y);
    printf("Hello, World!\n");
    return 0;
}

