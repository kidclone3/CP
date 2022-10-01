#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test(int pid) {
  if (pid < 0) {
    printf("Cannot create the child process\n");
  }
  if (pid == 0) {
    printf("hello from the child\n");
  } else {
    printf("hello from parent. Child's pid=%d\n", pid);
  }
}

int main() {
  test(fork());
  test(fork());
  test(fork());
  return 0;
}
