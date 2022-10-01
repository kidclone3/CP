#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid;
  pid = fork();
  if (pid == 0) { // it's the child process
    fork();
    printf("medium\n");
    fork();
    fork();
    printf("small\n");
  } else
    printf("big\n");
}
