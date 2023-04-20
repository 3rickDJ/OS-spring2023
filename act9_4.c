#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define LLAVE 234
#define MAX 10

int main(){
	int shmid, i;
	key_t key=LLAVE;
	char *vector;

	shmid=shmget(key, (MAX*sizeof(char)), IPC_CREAT | 0600);
	if(shmid==-1){
		printf("No se ha podido creaar el segmento\n");
		exit(-1);
	}
	else{
		vector=shmat(shmid,0,0);
		if(vector == (char *)0){
			printf("Error en la conexion\n");
			exit(-1);
		}
		printf("Segmento mapeado(asociado)\n");
		for(i=0; i<MAX; i++)
			vector[i]='a';
		for(i=0; i<MAX; i++)
			printf("Valor almacenado %c \n", vector[i]);
	}
	if(shmdt(vector)==-1){
		printf("Error de desconexion");
		exit(-1);
	}else{
		printf("Exito en la desconexion");
	}

	if (shmctl(shmid, IPC_RMID,0)== -1)
	{
		printf("Error en el borrado de segmento");
		exit(-1);
	}else{
		printf("Borrado de memoria compartida");
	}
	
}
