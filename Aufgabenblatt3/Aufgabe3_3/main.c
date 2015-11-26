

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_THREAD 20
#define WAIT 11


//Mutes zum sperren und entsperren Tanenbaum buch seite 180 bzw man/pthread_mutex_init
static pthread_mutex_t mt_counter;
static pthread_mutex_t mt_id;


//Globaler counter anzahl threads
int thread_counter;
int total_wait_time;

//Speichert infos des Threads
typedef struct{
    int thread_counter;
    int wait_time;
}info_block;

void *lawine (void *args){

    info_block *ptr_info;
    info_block local_thread;
    info_block next_thread[2];
    int counter;
    int i=0;
        pthread_t t_children[2];

    ptr_info = args;
    local_thread = *ptr_info;
        counter=0;

    printf("Hello from %d thread \n",local_thread.thread_counter);
    sleep(local_thread.wait_time);

        //Kritischer Abschnitt

            pthread_mutex_lock(&mt_counter);

                while((MAX_THREAD-thread_counter)>0&&i<2){
                    next_thread[i].wait_time=rand()%WAIT;
                    total_wait_time=total_wait_time+next_thread[i].wait_time;
                    thread_counter = thread_counter + 1;
                    next_thread[i].thread_counter=thread_counter;
                    pthread_create(&t_children[i],NULL,lawine,&next_thread[i]);
                    i++;
                }
    pthread_mutex_unlock(&mt_counter);
    for(i;i>0;i--){
        pthread_join(t_children[i],0);
    }

        printf("By from %d thread\n",local_thread.thread_counter);
}

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
int main(void){

        //random für die creat evt ?   int random1 = rand() % Wait;
        info_block thread_info;

    thread_info.thread_counter=1;
    thread_info.wait_time=rand()%WAIT;

        pthread_mutex_init(&mt_counter,0);
    pthread_mutex_init(&mt_id,0);
    pthread_t thread;

    thread_counter=1;

        pthread_create(&thread,NULL,lawine,&thread_info);
        pthread_join(thread,NULL);

        printf("Time waited for threads %d s\n",total_wait_time);
}

