#include <stdio.h>
#include <stdlib.h>


int main() {
    int i, n;
    char **p;
    scanf("%d", &n);
    p = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        p[i] = malloc(100*sizeof(char));
        gets(p[i]);
    }
    for(i=0;i<n;i++) puts(p[i]);
    for(i=0;i<n;i++) free(p[i]);
    free(p);
    printf("Hello, World!\n");
    return 0;
}

