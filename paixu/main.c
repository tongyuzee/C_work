#include <stdio.h>
//#include <stdlib.h>

void swap(int *a, int *b);
void bubble(int *a, int n );
void output(int *a, int n);

int main() {
    int num=0, i, a[10]={0};
    scanf("%d", &num);
    for ( i = 0; i < num; ++i)
    {
        scanf("%d", a+i);
    }
    bubble(a, num);
    output(a, num);
    return 0;
}
void bubble(int *a, int n )
{
    /*
     * 冒泡排序
     */
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (a[j] > a[j+1])
                swap(a+j,a+j+1);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void output(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}