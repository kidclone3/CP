// producer consumer using concurrent processes
//  gcc -pthread <program.c> -lrt
//  remember to put -lrt at the end

#include <stdio.h>
#include <sys/mman.h>
#include <sys/fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <semaphore.h>

#define DELAY(S) sleep(rand() % S)

void chaGuiTien(int amount);
void conRutTien(int amount);
const int timeGui = 2;
const int timeRut = 2;
// shared memory
struct mySharedMem
{
	int account;
} * pMem;

// Semaphore to lock process.
sem_t mutex;

int main()
{
	pid_t pid, cid;
	int shmfd;
	int status;

	// Create unsized shared memory object;
	shm_unlink("mySharedMemObject"); // remove the object, in case it exists
	shmfd = shm_open("mySharedMemObject", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
	assert(shmfd != -1);

	// Resize the region to store 1 struct instance
	assert(ftruncate(shmfd, sizeof(struct mySharedMem)) != -1);

	// Map the object into memory so file operations aren't needed
	pMem = mmap(NULL, sizeof(struct mySharedMem), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
	assert(pMem != MAP_FAILED);

	// Initialize shared data
	// ...
	printf("Ban dau trong tai khoan co: ");
	int amount;
	scanf("%d", &amount);
	pMem->account = amount;

	// create a child process to run chaGuiTien()
	pid = fork();
	if (pid == 0)
	{ // child process
		chaGuiTien(3);
		DELAY(2);
		munmap(pMem, sizeof(struct mySharedMem)); // unmap the object
		return 0;
	}
	else
	{				  // parent process
		cid = fork(); // create a child process to run conRutTien()
		if (cid == 0)
		{ // child process
			conRutTien(3);
			DELAY(3);
			munmap(pMem, sizeof(struct mySharedMem)); // unmap the object
			return 0;
		}
	}

	// parent process
	wait(NULL);
	waitpid(pid, &status, 0);
	waitpid(cid, &status, 0);
	printf("Well done. Let's go home\n");
	munmap(pMem, sizeof(struct mySharedMem)); // unmap the object
	shm_unlink("mySharedMemObject");		  // remove the object
	return 0;
}

void chaGuiTien(int amount)
{
	int x, i;
	for (i = 0; i < 5; i++)
	{
		// ...			// get the account value to local variable x
		sem_wait(&mutex);
		x = pMem->account;
		DELAY(timeGui);
		// ...			// increase x by amount
		x += amount;
		DELAY(timeGui);
		// ...			// write the value of x back to the account
		pMem->account = x;
		DELAY(timeGui);
		sem_post(&mutex);
		printf("Tao da gui. Account=%d\n", pMem->account);
		// printf("Tao da gui. Account=%d\n", x);
	}
}

void conRutTien(int amount)
{
	int y, i;
	for (i = 0; i < 5; i++)
	{
		// ...			// get the account value to local variable y
		sem_wait(&mutex);
		y = pMem->account;
		DELAY(timeRut);
		// ...			// decrease y by amount
		y -= amount;
		DELAY(timeRut);
		if (y >= 0)
		{
			// ...		// write the value of y back to the account
			pMem->account = y;
			sem_post(&mutex);

			printf("Con da rut. Account=%d\n", pMem->account);
			// printf("Con da rut. Account=%d\n", y);
		}
		else
		{
			sem_post(&mutex);

			printf("Khong du tien\n");
			// i--;
		}
		DELAY(timeRut);
	}
}