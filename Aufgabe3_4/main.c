#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>

//Anzahl an threads die erstellt werden sollen
#define MAX_THREADS 20
//Anzahl der maximalen Kinder pro Thread
#define MAX_CHILDREN 16

/**
 * Rundet einen wert auf der ab.
 * value:      Der wert der abgerundet werden soll
 * return:int  Auf oder abgerundeter int wert des einegegebenen double werts
 */
int floor(double value);


/**
  gibt an wie viele kinder pro thread erzeugt werden soll
  max:      Die maximal anzahl an Kinder threads
  value:    Errechnete anzahl an kinder Threads
  return:   Wenn max nicht ueberschritten wurde value ansonsten max
 */
int min(int value,int max);

/**
 * Erstellt threads
 * args:    Pointer auf lokale daten die fuer den Thread von bedeutung sind
 */
void *function(void *args);

static pthread_mutex_t block;

//Anzahl an erstellten threads
int totalThreads;

int main(void)
{


}

void *function(void *args){


}



int floor(double x){
    int y= x;
    if((x-((double)y))>=0.5){
        return y+1;
    } else {
        return y;
    }
}

int min(int value, int max){
    if (value>max) {
        return max;
    }
    return value;
}



