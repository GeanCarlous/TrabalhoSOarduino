#include "kernel.h"
#include <unistd.h> //para usar o sleep()

//definição do poolsize
#define POOLSIZE 10

static process* pool[POOLSIZE];


//variavel global
int start=0, end=0;

char kernelInit(void){
    start=0;
    end=0;
    return SUCCESS;
}

//adiciona os processos na pool
char kernelAddProc(process* func){
    //adiciona os processos somente se houver espaço livre
    // o fim nunca pode coincidir com o inicio
    if(((end+1)%POOLSIZE) != start){ //essa linha proteje o espaço depois do ultimo 
        
        //add o novo processo e agenda para exec imediatamente
        func->deadline += func->period;
        pool[end] = func;
        end = (end+1)%POOLSIZE;
        return SUCCESS; //cso tenha dado certo
    } else {
        return FAIL; //caso dê errado, pool cheia
    }
}


void kernelLoop(void){
    unsigned int count;
    unsigned int next;
    process* tempProc;
    for(;;){ //loop infinito
        if(start != end){
            //procura a próxima função a ser exec com base no tempo
            count = (start+1)%POOLSIZE;
            next = start;
            while(count != end){
                if((pool[count]->deadline) < (pool[next]->deadline)){
                    next = count;
                }
                count = (count+1)%POOLSIZE; //proximo processo
            }
            //troca processo de menor tempo como o primeiro
            tempProc = pool[next];
            pool[next] = pool[start];
            pool[start] = tempProc;
            while((pool[start]->deadline) > 0){
                //coloca a CPU em mode de economia de energia
            }
            //retorna se precisa repetir novamente ou não
            switch (pool[start]->func())
            {
                case REPEAT:
                    kernelAddProc(pool[start]);
                    break;
                case FAIL:
                    break;
                default:
                    break;
            }
            start = (start+1)%POOLSIZE; //prox processo
        }
    }
}