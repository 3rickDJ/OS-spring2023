#include <stdio.h>

int main() {
  int a[10], *pa, x;
  a[0] = 11;
  a[1] = 22;
  a[2] = 33;
  a[3] = 44;
  pa = a;
  x = *pa;
  pa++;
  x = *pa;
  x = *pa + 1;
  x = *(pa + 1);
  x = *++pa;
  x = ++*pa;
  printf("El valor de x=%d \n", x);
  printf("El valor de p=%p \n", pa[2]);
  printf("El valor de pa=%d \n", pa);
  printf("El valor de pa%d \n", pa[2]);
}
