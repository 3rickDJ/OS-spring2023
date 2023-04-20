#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void atrapa(int sig)
{
  signal(sig, atrapa);
  printf("SIGUSR1, magnicidio\n");
}

int main()
{
  pid_t padre, hijo;
  padre = getpid();
  signal(SIGUSR1, atrapa);
  if ((hijo = fork()) == 0)
  {
    sleep(1);
    kill(padre, SIGUSR1);
    sleep(1);
    kill(padre, SIGUSR1);
    sleep(1);
    kill(padre, SIGUSR1);
    sleep(1);
    kill(padre, SIGKILL);
  }
  else
    for (;;)
      ;
}