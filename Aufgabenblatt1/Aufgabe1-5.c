#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	

	pid_t pid;
	int j=5;
	if(pid=fork()){
		j=j*j;
		printf("Das ergebnis von 5*5 ist %d \n",j);
	}else if(pid==0){
		j = j*4;
		printf("Das ergebnis von 5*4 ist %d \n",j);
	}
	
	return 0;

}

