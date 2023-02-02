#include <stdio.h>

int main(){
    float x, mitad();
    printf("El valor de X antes de enviarse %3.4f\n",x);
    x = mitad();
    printf("El valor de X sin parametros %3.4f\n",x);
    x = mitad(2,5);
    printf("El valor de X con 2 parametros %3.4f\n",x);
    x = mitad(7);
    printf("El valor de X con 1 parametro %3.4f\n",x);
    x = mitad(x);
    printf("El valor de X con el mismo parametro %3.4f\n",x);
}
float mitad (int num){
    return (num/2.0);
}
