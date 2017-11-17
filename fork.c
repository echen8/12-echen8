#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


// STUFF NOT WORKING: PARENT'S CHILD SLEEP TIME AND CHILD'S PID

int main() {
  
  srand( time(NULL) );

  printf( "======================================\n" );
  printf( "Some initial message\n" );

  int f1 = fork(); // First child and parent pid
  int f2; // Second child and parent pid

  // 2nd fork from parent
  if ( f1 ) {
    f2 = fork();
  }

  // PARENT
  if ( f1 && f2 ) {
    
    int status;
    int cpid = wait( &status );
    
    printf( "P| First place child: %d\tSlept for %d seconds\n", cpid, WEXITSTATUS( status ) );
    printf( "P| Parent finished!\n" );

    exit(1);
  }
  
  // CHILD
  if ( !f1 || !f2 ) {
    printf( "C| pid: %d\n", getpid() );
    int sleeptime = ( rand() % 16 ) + 5;
    sleep( sleeptime );
    printf( "C| pid%d finished.\n", getpid() );
    return sleeptime;
  }

  return 0;
}

	
	
	
