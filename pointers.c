#include <stdio.h>

main(void){
    static char *b[]={"menos", "mas", "grande"};
    static char **d[]={b,b+1,b+2};
    char *p;
    printf("%s\n", *(b+1));
    printf("1.- %c\n", *(b[0]+2));
    printf("2.- %c\n", *(*b+2));
    printf("3.- %c\n", **(b+2));

    printf("%s\n", *(b+1));
}
