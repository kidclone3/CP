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
struct mySharedMem {
	char buf[256];
} *pMem;

int main() {
	pid_t pid;
	int shmfd;
		
	// Create unsized shared memory object;
	shm_unlink ("mySharedMemObject");	// remove the object, in case it exists
	shmfd = shm_open ("mySharedMemObject", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
	assert (shmfd != -1);
	
	// Resize the region to store 1 struct instance
	assert (ftruncate (shmfd, sizeof (struct mySharedMem)) != -1);
	
	// Map the object into memory so file operations aren't needed
	pMem = mmap (NULL, sizeof (struct mySharedMem),PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
	assert (pMem != MAP_FAILED);
	
	// Initialize shared data
	printf("Type a message to the child: ");
    fgets(pMem->buf, 255, stdin); // get user's input, 255 chars maximum to buf
	
	// create a child process
	pid = fork();
	if (pid == 0) { // child process
		// convert to uppercase
        for (int i = 0; i < strlen(pMem->buf); ++i) {
			pMem->buf[i] = toupper(pMem->buf[i]);
		}
		munmap (pMem, sizeof (struct mySharedMem)); // unmap the object
		return 0;
	}
	
	// parent process, wating for the child to exit
	wait(NULL);
	
	printf("Message from the child: %s\n", pMem->buf);	// print out the string in buf
	munmap (pMem, sizeof (struct mySharedMem)); 	// unmap the object
	shm_unlink ("mySharedMemObject");				// remove the object
	return 0;
}
