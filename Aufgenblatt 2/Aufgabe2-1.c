#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
	pid_t pid;
	int status;
	pid = fork();
	if(pid==0){
		printf("I'm the child, my PID is:%d\n",getpid());
	}else if(pid>0){
		printf("I'm the parent, my PID is:%d\n",getpid());
		printf("Waiting for my child\n");
		wait(&status);
		printf("This was the status off the child:%d\n",status);
		printf("I'm the parent and i'm done\n");
	}
}
