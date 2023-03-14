#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void){
  int fd, n;
  char buf[1024];
  fd=open("fifo2", O_RDONLY);
  n = read(fd, buf, sizeof(buf));
  printf("Número de bytes rx: %d \n", n);
  printf("RX mensaje: %s \n", buf);
  close(fd);
  return 0;
}
