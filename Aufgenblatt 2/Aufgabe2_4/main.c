//Sven Marquardt und Sheraz Azad
// myfamily.c (aka bsp7a.c )
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define HOWMANYCHILDS 4

int main() {
    int i;
    int j;
    int waitId;
    int status;
    int fork_value = 1;
    int sleep_state=4;
    int childrens[HOWMANYCHILDS]={0};


    for( i = 0; i < HOWMANYCHILDS; i++ ) {
        //Schaut ob es sich um einen Vater handelt wenn ja fork() und dekrementiert sleep_state um einen
        //sleep_state sorgt dafuer, dass sich die Prozesse von untern nach oben beenden
        if( fork_value > 0) {
            fork_value = fork();
            childrens[i]=fork_value;
            //Jedes Kind meldet sich
            if(fork_value==0){
                printf("Hello, my PID is %d, my parents PID is %d\n",getpid(),getppid());
                //Setze i auf anzahl der for durchläufe um zu verhindern das Kinder den Prozess nochmal durchgehen
                i=HOWMANYCHILDS;
                for(j=0;j<2;j++){
                    //Beginne 2. runde
                    fork_value=fork();
                    if (fork_value==0) {
                        printf("Hello, my PID is %d, my parents PID is %d\n",getpid(),getppid());
                        fork();
                        if(fork_value==0) printf("Hello, my PID is %d, my parents PID is %d\n",getpid(),getppid());
                        //Wieder setze j=2 damit die kinder nicht wieder die forscheleife starten.
                        j=2;
                    }
                }
            }
            //Damit der oberste vater am kürzesten wartet.
            sleep_state=sleep_state+1;
        }

    }
    waitId=0;
    sleep(sleep_state);
    //vater wartet auf beendigung aller Kinder
    //Aus der man:  WNOHANG return immediately if no child has exited.
    //Also benutze waitpid und frage auf rückgabe 0 denn dann gibt es kein weiteres kind mehr
    while (waitpid(childrens[waitId],&status,WNOHANG)!=0) {
        printf("Waiting for my Childrens %d\n",childrens[waitId]);
        waitId+=waitId+1;
    }
    //Alle Prozesse verabschieden sich
    printf("... und tschüss %d.\n", getpid());
}

