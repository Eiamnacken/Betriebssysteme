//Sven Marquardt und Sheraz Azad
// myfamily.c (aka bsp7a.c )
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//wie viele unterprozesse
#define MAXCHILDRENS 20

/**
 * Erstellt einen baum mit 20 unterprozessen
 */
int main() {
    int i;
    int status;
    int fork_value;
    int sleep_stat=1;
    //Starte bei 4 weil erste generation braucht 4 kinder
    int generation=4;
    //Anzahl an kindern reduzieren
    int dividend=2;
    //Anzahl der Kinder für jeden prozess
    int children=0;


    for( i = 0; i < MAXCHILDRENS; i++ ) {
        if(generation!=children&&generation!=0){
            fork_value=fork();
            if (fork_value==0) {
                children=0;
                //Wenn an der letzten generation setze generation auf 0
                //weil keine kinder mehr gebracuht werden
                if (dividend!=1) {
                    //Dividiere durch dividend um die anzahl an kindern zu reduzieren
                    generation=generation/dividend;
                }else {
                    generation=0;
                }
                printf("Hello, my PID is %d, my parents PId is %d\n",getpid(),getppid());
                //So wartet der oberst Vater am kürzesten
                sleep_stat=sleep_stat+1;
            }else if(fork_value>0){
                children=children+1;
            }
        }

    }
    sleep(sleep_stat);
    if(fork_value>0){
        if (children==1) {
            printf("Waiting for my child\n");
        }else {
            printf("Waiting for my %d children\n",children);
        }
        for (i=0; i < children; i++) {
            wait(&status);

        }
    }
    printf("... und tschüss %d\n",getpid());
}

