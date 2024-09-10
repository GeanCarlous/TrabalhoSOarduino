#include <stdio.h>
#include "kernel.c"
#include "kernel.h"

int main(){
    printf("...........Sistema Iniciado\n");
    //declara os processos
    process pl = {1,0};
    process p2 = {2,14};
    process p3 = {5,20};

    kernelInit();

    if (kernelAddProc(&pl) == SUCCESS){
        printf("1st process added\n");
        }

    if (kernelAddProc(&p2) == SUCCESS){
        printf("2st process added\n");
        }

    if (kernelAddProc(&p3) == SUCCESS){ 
        printf("3st process added\n");
        }

    kernelLoop();





    return 0;
}