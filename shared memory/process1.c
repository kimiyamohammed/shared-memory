#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <time.h>
#define SHMSZ 40
int main(){
int shmid;
int *shm;
int key;
key = 1122;
int r;
if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {	
	printf("error creating shared memory segment\n");
	exit(1);
}
if((shm = shmat(shmid, NULL, 0)) == (int *) -1){
	printf("error attaching shared memory segment\n");
	exit(1);
}

srand(time(NULL));
r = rand() % 10;
*shm = r;
shmdt(shm);
exit(0);
}
