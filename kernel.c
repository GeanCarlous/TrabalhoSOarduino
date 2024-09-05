#include "kernel.h"
#include <unistd.h> //para usar o sleep()

//definição do poolsize
#define POOLSIZE 10

process* pool[POOLSIZE];


//variavel global
int start=0, end=0;

char kernelInit(void){
    //vai ter algo ainda
    return SUCCESS;
}

char kernelAddProc(process* newProc){
    if(end<POOLSIZE){
        pool[end] = newProc;
        end++;
        return SUCCESS; //cso tenha dado certo
    } else {
        return FAIL; //caso dê errado, pool cheia
    }
}


void kernelLoop(void){
    int i;
    int contador = 0;
    for(;;){ //loop infinito
        for(i=0;i<end;i++){
           if (pool[i] != NULL && pool[i] ->func != NULL){
                pool[i]->func(++contador); //exec a função
        }
        sleep(1);
        }
    }
}