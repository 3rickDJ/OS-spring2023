# Practica 3. Argumentos para Main

## Objetivo

Aprender a ingresar parámetros en linea de comandos.

## Desarrollo

Un SO es un conjunto de herramientas escritas en C, por ello, C es ideal para construir un sistema operativo.

### Primera Forma de Usar los Parámetros argc y argv

```c++
#include <stdio.h>

main(int argc, char **argv){
	if(argc < 2){
		printf("Ha olvidado su nombre \n");
	} else if (argc > 2){
		printf("Son demasiados parámetros \n");
	} else {
		printf("Hola %s\n", argv[1]);
	}
}
```

### Segunda forma

```c++
#include <stdio.h>

main(argc, argv){
	// ...
}
```

### Tercera forma

```c++
#include <stdio.h>

main(int argc, char *argv[]){
	// ...
}
```

### Cuarta forma

```c++
#include <stdio.h>

int main(int num_args, char **argStrings){
	// ...
}
```

### Paso de Argumentos

Para pasar argumentos y usarlos en nuestro ejecutable, utilizaremos los parámetros `argc` y `argv`.

`argc` es de tipo `integer` y contiene el numero de parámetros ingresados de la consola.

`argv` es un **arreglo** de tipo `char` y contiene el valor de los parámetros ingresados previamente.

Por ejemplo, enviaremos 3 argumentos:

```bash
./codigo.o soy varios argumentos
```

El `argv` tendría los siguientes valores:

Posición  | Valor
----------|-----------
`argv[0]` | codigo.o
`argv[1]` | soy
`argv[2]` | varios
`argv[3]` | argumentos

> El nombre del ejecutable siempre estará en la posición `0`

## Primer Ejemplo. Nombre Completo

```c++
#include <stdio.h>

main(int argc, char **argv){ // argc = numero de parametros, argv = parametros
	// argv[0]: Nombre del archivo

	for (int i = 1; i < argc; i++){
		printf("%s ", argv[i]);
	}
	printf("\n");
}
```

## Segundo Ejemplo. Suma de n Números positivos

```c++
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

```

### Ejemplo 3. Lectura de archivo

```c++
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BYTES_BUFFER 512

int main(){
	int arch;

	int i, leido;

	char buffer[ BYTES_BUFFER ];

	arch = open("suma.c", O_RDONLY); // nombre del archivo
	if(arch < 0){
		printf("Error al abrir el codigo");
		exit(-1);
	}

	while((leido=read(arch, buffer, BYTES_BUFFER)) > 0){
		for(i=0; i<leido; i++){
			putchar(buffer[i]);
		}
	}

	close(arch);

	if (leido < 0){
		printf("Error al leer el archivo ");
		exit(-2);
	}
}
```
