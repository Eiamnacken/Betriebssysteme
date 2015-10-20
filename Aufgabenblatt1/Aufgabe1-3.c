#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	

	pid_t pid;
	
	if(pid=fork()){
		printf("Meine nummer ist %d und die meines Vaters %d\n",getpid(),getppid());
	}else if(pid==0){
		sleep(1);
		printf("Meine nummer ist %d und die meines Vaters %d\n",getpid(),getppid());
	}
	
	return 0;
}

