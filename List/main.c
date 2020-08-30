#include <stdio.h>
#include <stdlib.h>

int main() {
    int *A, i, j, m, n;
    scanf("%d %d", &m, &n);
    A = (int *)malloc(m * n *sizeof(int));
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",A+i*m+j);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",*(A+i*m+j));
        printf("\n");
    }
    free(A);
    printf("Hello, World!\n");
    return 0;
}
