#include <stdio.h>

int main() {
    short int A[5]={1,2,3,4,5};
    A[3] = 9;
    printf("%llu\n",sizeof(A));
    printf("%llu\n",sizeof(A+1));
    printf("%llu\n",sizeof(*(A+0)));
    printf("%llu\n",sizeof(sizeof(A)));
    int i, j;
    i = 0;
    j = 4;
    i = (j++) * (j++);

    printf("Hello, World!\n");
    return 0;
}
