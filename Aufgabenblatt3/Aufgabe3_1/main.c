#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int variable=2;
pthread_t threads[2];

void* showThread(void *args) {

    if(pthread_equal(pthread_self(),threads[0])){
        printf("Hello from the first thread\n");
    }else {
        printf("Hello from second thread\n");
    }

    return NULL;

}

int main(void)
{


    int error;
    int i=0;
    pthread_attr_t attr;

    while (i<2) {
        error=pthread_create(&(threads[i]),NULL,&showThread,NULL);
        if (error!=0) {
            printf("Error, can't create thread\n");
        }else {
            printf("Thread created!\n");
        }
        i=i+1;

    }

    sleep(5);



}

