#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


// STUFF NOT WORKING: PARENT'S CHILD SLEEP TIME AND CHILD'S PID

int main() {
  
  srand((unsigned int)time(NULL));
  int r;

  printf("Some initial message\n");

  int f1 = fork();
  int f2 = fork();

  // PROBLEM??
  int cpid = wait( NULL );

  // Actions for child processes.
  if (f1 == 0 && f2 == 0) {

    r =  (rand() % 15) + 5;
    
    printf("I'm a child: %d\t f1: %d\t parent : %d\n", getpid(), f1, getppid());
    sleep( r );
    printf("I'm a child: %d\t f2: %d\t parent : %d\n", getpid(), f2, getppid());
	
    printf("A message that it is finished\n");
  }

  // NOT WORKING
  printf( "Child's pid: %d\tSleep time:%d\n", cpid, r );

  printf( "\nA message that the parent is done\n" );

  exit(0);

  return 0;
}

	
	
	
