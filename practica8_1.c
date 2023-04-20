#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void atrapa(int);

int main(){
    int i;
    for(i=0; i<=64;i++){
        signal(i,atrapa);
    }
    printf("Identificativo de proceso: %d\n",getpid());
    pause();
    printf("Continuando...\n");
}

void atrapa(int sig) {
    signal(sig,atrapa);
    printf("Recibida la senal: %d\n",sig);
}    