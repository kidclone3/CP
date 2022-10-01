#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
int main()
{
  char *msg = "Hello child\n", buf[255];
  int fd[2], pid;

  memset(buf, 0, 255);
  if (pipe(fd) < 0)
    exit(-1);
  if ((pid = fork()) > 0)
  { // parent
    close(fd[0]);
    write(fd[1], msg, strlen(msg));
    wait(NULL); // wait for the child to exit
  }
  else
  { // child
    close(fd[1]);
    read(fd[0], buf, 254);
    printf("%s\n", buf);
  }
  return 0;
}
