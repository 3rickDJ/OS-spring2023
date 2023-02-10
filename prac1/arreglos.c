#include <stdio.h>

int main() {
    int i;
    int a[5];
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    printf("Se imprime arreglos pasandose de parametros\n");
    /* printf("a[%d]=%d \n", i, a[i]); */
    for (i = 0; i < 7; i++)
        printf("a[%d]=%d \n", i, a[i]);
    /* a[3]=8; */
    3[a]=8;
    printf("%d\n",3[a]);
    a[-2]=6;
    printf("%d\n", a[-2]);
}
