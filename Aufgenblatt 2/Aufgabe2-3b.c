
//Sven Marquardt und Sheraz Azad 
// myfamily.c (aka bsp7a.c )
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int status;
	int fork_value = 1;
	int sleep_state=4;



	for( i = 0; i < 3; i++ ) {
		//Schaut ob es sich um einen Vater handelt wenn ja fork() und dekrementiert sleep_state um einen
		//sleep_state sorgt dafuer, dass sich die Prozesse von untern nach oben beenden
		if( fork_value > 0) {
			fork_value = fork();
			//Jedes Kind meldet sich
			if(fork_value==0){
				printf("Kind: PID: %d; PPID: %d\n", getpid(), getppid());
			}
			sleep_state=sleep_state-1;
		}
		//Vater ausgeben
		if( fork_value > 0 && i==0) {
			printf("I am the father: %d \n", getpid());
		}

	}
	
	sleep(sleep_state);
	//vater wartet auf beendigung eines Kindes
	if (fork_value > 0){
		printf("I'm process %d. Waiting for one of my children to complete.\n", getpid());
		wait(&status);
	}
	//Alle Prozesse verabschieden sich
	printf("... und tschüss %d.\n", getpid());
}
