#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 5;
int main() {
  pid_t pid;
  pid = fork();
  if (pid == 0) { /* child process */
    value += 15;
    // printf("CHILD: value = %d\n", value); // dong A
    return 0;
  } else if (pid > 0) { /* parent process */
    wait(NULL);         /* wait for the child process to terminate */
    printf("PARENT: value = %d\n", value); // dong A
    return 0;
  }
}
