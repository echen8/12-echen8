#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


// STUFF NOT WORKING: PARENT'S CHILD SLEEP TIME AND CHILD'S PID

int main() {
  
  srand(time(NULL));
  int r;

  printf("======================================\nSome initial message\n");

  int f1 = fork();
  int f2 = fork();

  int cpid;
  wait( &cpid );

  // Actions for child processes.
  if (f1 == 0 && f2 == 0) {

    r =  (rand() % 15) + 5;
    
    printf("C| PID: %d\tPPID: %d\n", getpid(), f1, getppid());
    sleep( r );
	
    printf( "Child#%d process finished.\n", getpid() );
  }

  // NOT WORKING
  printf( "A| PID: %d\tChild's pid: %d\tChild's sleep time:%dms\n", getpid(), cpid, r );

  printf( "A message that the parent is done\n" );

  exit(0);

  return 0;
}

	
	
	
