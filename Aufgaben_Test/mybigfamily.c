// myfamily.c (aka bsp7a.c )
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {
	int i;
	int j;
	int k = 0;
	int status, a = 0, b = 0, c = 0;
	int ebene_1 = 1, ebene_2 = 0;
//----------------------------------------------------------------------------------------------
	for( i = 0; i < 4; i++ ) {
		if( ebene_1 > 0) {
			ebene_1 = fork();
			ebene_2 = ebene_1;
			for(j = 0; j < 2; j++){
				if(ebene_2 == 0){
					ebene_2 = fork();
					if((ebene_2 > 0) && j == 0){
						ebene_2 = fork();
					}
				}
			}
		}

		if( ebene_1 >  0 && i == 0) {
			printf("\nI am the father: %d\n \n", getpid());
			a = getpid();
		}
	}

	if (ebene_1 == 0) {
		printf("Hello my PID is: %d,	my parent's PID is: %d.\n", getpid(), getppid());
	}
	sleep(3);

	while (wait(status) >0){
		printf("I'm %d\n", getpid());
	}
/*
	if(i == 4 && j ==2){
	printf("\nI'm process %d. Waiting for my %d children to complete.\n", a, i);
	wait(&status);
	}

	wait(&status);

	printf("I'm process %d and I'm done.\n", getpid());
*/
}
