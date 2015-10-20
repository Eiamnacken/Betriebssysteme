#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	

	pid_t pid;
	
	printf("Die Vater Id der folgenden Porzesse ist %d\n",getpid());
	pid = fork();

	if(pid>0){
		printf("Der Vater %d und der UrgroßVater %d\n",getpid(),getppid());
	}else if(pid==0){
		sleep(1);
		printf("Meine nummer ist %d und die meines Vaters %d\n",getpid(),getppid());
	}
	
	return 0;
}

