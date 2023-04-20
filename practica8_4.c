#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int pid, i = 10;
    if ((pid = fork()) == 0)
    {
        while (i != 0)
        {
            printf("Hijo.pid = %d \n", getpid());
            i--;
            sleep(1);
        }
    }
    else
    {
        sleep(10);
        printf("Padre.terminacion de proceso: %d \n", getpid());
        // kill(pid,SIGTERM);
        // CAmbiamos valores
        kill(pid, SIGSTOP);
    }
    exit(0);
}