#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void atrapa(int);

int main() {
  pid_t padre, hijo;
  padre = getpid();
  signal(SIGUSR1, atrapa);
  if( (hijo=fork()) == 0 )
      {
      sleep(1);
      kill(padre, SIGUSR1);
      sleep(1);
      kill(padre, SIGUSR1);
      sleep(1);
      kill(padre, SIGUSR1);
      sleep(1);
      kill(padre, SIGUSR1);
      sleep(1);
      kill(padre, SIGUSR1);
      exit(0);
      }
  else
      { /* padre */
       for(;;);
      }
  return 0;
}

void atrapa(int sig)
{
  signal(sig, atrapa);
  printf("SIGUSR1,magnicidio%d\n:   ", sig);
}