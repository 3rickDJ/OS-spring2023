#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void){
  int fd;
  char buf[]="Hola, pasé por la tubería";
  mkfifo("fifo2", 0666);
  fd=open("fifo2", O_WRONLY);
  write(fd, buf, sizeof(buf));
  close(fd);
  return 0;
}
