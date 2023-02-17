#include <stdio.h>

main(int argc, char **argv){ // argc = numero de parametros, argv = parametros
	// argv[0]: Nombre del archivo

	for (int i = 1; i < argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n");


}
