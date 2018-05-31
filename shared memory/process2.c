#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#define SHMSZ 40

int main(){
int shmid;
int *shm;
int key = 1122;
if((shmid = shmget(key, SHMSZ, 0666)) < 0){
	printf("error creating shared memory segment\n");
	exit(1);
}
if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
	printf("error attaching shared memory segment\n");
	exit(1);
}
int n = *shm;
int flag = 0;
for(int i = 1; i < n / 2; i++){
	if(n % i == 0){
		flag = 1;
		printf("%d is prime number \n", n);
		break;
	}
}
if(flag == 0){
	printf("%d is composit number \n", n);
}

shmdt(shm);
shmctl(shmid, IPC_RMID, 0);
exit(0);
}
