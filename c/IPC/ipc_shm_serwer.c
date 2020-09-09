#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSIZE 100

int main(int argc, char *argv[])
{
	int shmid;
	key_t key;
	char *shm, *s;

	key = 1234;
	shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666);
	
	if(shmid <0)
	{
		perror("shmget");
		exit(1);
	}

	shm = shmat(shmid, NULL, 0);

	if(shm == (char *) -1)
	{
		perror("shmmat");
		exit(1);
	}

	memcpy(shm, "Wiadomosc", 9);
	s = shm;
	s += 9;
	
	*s = 0;

	while(*shm != '*')
		sleep(1);
	

	return 0;
}
