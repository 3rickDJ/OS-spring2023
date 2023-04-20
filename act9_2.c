#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define TAM_BUF 4096

main(int argc,char *argv[]){
	int id,salida,i;
	char *buf_sgtmemc;

	if(argc !=2){
		puts("MODO DE EMPLEO: abrir_sgtmemc <identificador>");
		exit(-1);
	}
	id=atoi(argv[1]);
	if((buf_sgtmemc=shmat(id,0,0)) < (char *)0){
		perror("shmat");
		exit(-1);
	}
	if((buf_sgtmemc=malloc(sizeof(char)*TAM_BUF))==NULL){
		perror("malloc");
		exit(-1);
	}

	for(i=0;i< TAM_BUF;i++)
		buf_sgtmemc[i]=i%127;
	salida=open("text.c",O_CREAT|O_WRONLY,0600);
	write(salida,buf_sgtmemc,TAM_BUF);
	close(salida);
	printf("Eliminando memoria compartida");
	shmctl(id,IPC_RMID,0);
	exit(0);
}
