#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
	srand((unsigned int)time(NULL));

	printf("Some initial message\n");
	

	int f1 = fork();
	int f2 = fork();
	
	if (f1 == 0 && f2 == 0){

		printf("I'm a child: %d\t f1: %d\t parent : %d\n", getpid(), f1, getppid());
		sleep( ((rand() % 15) + 5) );
		printf("I'm a child: %d\t f2: %d\t parent : %d\n", getpid(), f2, getppid());
	
		printf("Finished with processing\n");
	}


	
	
	
