// myfamily.c (aka bsp7a.c )
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//Gibt die Kinder eines Vaterprozesses aus
void printChilds(int childs[],size_t size);

int main() {
	int childs[4];
	int fork_value=1;
	int i=4;
	for(;i>0;i--){
		if(fork_value>0){
			fork_value=fork();
			printf("Hello, my PID is: %d, my parents PID is %d\n",getpid(),getppid());
		}
		if(fork_value==0){
			*childs=getpid();
			*childs=*childs+1;
		}
	}
	printChilds(childs,4);
}



void printChilds(int childs[4],size_t size){
	size_t i = 0;
	for(i=size-1;i>0;i--){
		printf("%d\n",*childs+1);
	}
}


