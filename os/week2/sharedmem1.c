//producer consumer using concurrent processes
// gcc <program.c> -lrt
// remember to put -lrt at the end

#include <stdio.h>             
#include <string.h>
#include <ctype.h>
#include <sys/mman.h>
#include <sys/fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// shared memory
struct permission {
  int user, group, other;
} * perm;

int main() {
  int shmfd =
      shm_open("MyFile_SHM", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
  assert(shmfd != -1);

  /* Resize the region to store 1 struct instance */
  assert(ftruncate(shmfd, sizeof(struct permission)) != -1);

  /* Map the object into memory so file operations aren't needed */
  struct permission *perm = mmap(
      NULL, sizeof(struct permission), PROT_READ | PROT_WRITE, MAP_SHARED,
      shmfd,
      0); // addr==NULL allows the kernel to choose the addr for the mapping
  assert(perm != MAP_FAILED);

  /* Create a child process and write to the mapped/shared region */
  pid_t child_pid = fork();
  if (child_pid == 0) { // child process
    perm->user = 6;
    perm->group = 4;
    perm->other = 0;

    /* Unmap and close the child's shared memory access */
    munmap(perm, sizeof(struct permission));
    close(shmfd);
    return 0;
  }

  /* Make the parent wait until the child has exited */
  wait(NULL);

  /* Read from the mapped/shared memory region */
  printf("Permission bit-mask: 0%d%d%d\n", perm->user, perm->group,
         perm->other);

  /* Unmap, close, and delete the shared memory object */
  munmap(perm, sizeof(struct permission));
  close(shmfd);
  shm_unlink("MyFile_SHM");
  return 0;
}
