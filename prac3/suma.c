#include <stdio.h>

main(int argc, char **argv){ // argc = numero de parametros, argv = parametros
	int total = 0;

	for (int i = 1; i<argc; i++){
		int d = (argv[i][0] - '0') * 10;
		int u = argv[i][1] - '0';

		total += (d+u);
	}

	printf("%d", total);
}
