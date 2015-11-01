// myfamily.c (aka bsp7a.c )
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int j;
	int status;
	int ebene_1 = 1;
	int ebene_2 = 0;
	int ebene_3 = 0;



	for( i = 0; i < 4; i++ ) {

		if( ebene_1 > 0) {
			ebene_1 = fork();
			ebene_2 = ebene_1;

			for(j = 0; j < 2; j++){
				if(ebene_2 == 0){
					ebene_2 = fork();
					ebene_3 = ebene_2;
					if((ebene_2 > 0) && j == 0){
						ebene_2 = fork();
					}
				}
			}

		}

		if( ebene_1 >  0 && i == 0) {
			printf("\n		I am the father: %d\n \n", getpid());
		}

	}

	if (ebene_1 == 0) {
		printf("Kind PID: %d; 	PPID: %d.\n", getpid(), getppid());
	}

	if (ebene_2 == 0){
		printf("Kind PID: %d,	PPID: %d.\n", getpid(), getppid());
	}

	sleep(1);
/*
	if (ebene_1 > 0){
		printf("I'm process %d. Waiting for one of my children to complete.\n", getpid());
		wait(&status);
	}

	printf("... und tschüss %d.\n", getpid());
*/
}
