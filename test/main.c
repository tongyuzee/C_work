#include <stdio.h>
//#include <stdlib.h>

/*
 * 冒泡排序
 */
int main() {
    int num=0, i, j, a[10]={0};
    scanf("%d", &num);
    for ( i = 0; i < num; ++i)
    {
        scanf("%d", a+i);
    }
    for (i = 0; i < num; i++)
        for (j = 0; j < num - i -1; j++)
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    for (i = 0; i < num; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}