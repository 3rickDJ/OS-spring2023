#include <stdio.h>

main(int argc, char **argv){
	printf("Valor: %s \n", argv[0]);
	if(argc < 2){
		printf("Ha olvidado su nombre \n");
	} else if (argc > 2){
		printf("Son demasiados parámetros \n");
	} else {
		printf("Hola %s\n", argv[1]);
	}
}
