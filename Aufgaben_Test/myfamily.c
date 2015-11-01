// myfamily.c (aka bsp7a.c )
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int status;
	int fork_value = 1;



	for( i = 0; i < 3; i++ ) {

		if( fork_value > 0) {
			fork_value = fork();
		}

		if( fork_value >  0 && i == 0) {
			printf("I am the father: %d \n", getpid());
		}

	}

	if (fork_value == 0) {
		printf("Kind: PID: %d; PPID: %d\n", getpid(), getppid());
	}

	sleep(1);

	if (fork_value > 0){
		printf("I'm process %d. Waiting for one of my children to complete.\n", getpid());
		wait(&status);
	}

	printf("... und tschüss %d.\n", getpid());
}
