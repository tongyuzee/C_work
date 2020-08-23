#include <stdio.h>

int main() {
    int i=0, n=5;
    while (--n>0){
        /* ++a表示取a的地址，增加它的内容，然后把值放在寄存器中 */
        i++;
        printf("%d %d\n", n, i);
    }
    i=0;n=5;
    while (n-->0){
        /* a++表示取a的地址，把它的值装入寄存器，然后增加内存中的a的值 */
        i++;
        printf("%d %d\n", n, i);
    }

}

