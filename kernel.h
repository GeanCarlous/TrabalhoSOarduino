#ifndef KERNEL_H_
#define KERNEL_H_

// código de retorno
#define SUCCESS 0
#define FAIL 1
#define REPEAT 2

// declaração de ponteiro de função
typedef char (*ptrFunc)(void);

// definição da estrutura de um processo
typedef struct {
    //ponteiro para a função a ser exec
    ptrFunc func;
    //periodo de reexecução da função
    int period;
    //contador de tempo de cada processo
    int deadline;
}process;

// protótipo das funções do kernel
char kernelInit(void);
char kernelAddProc(process* newProc);
void kernelLoop(void); //declaração de ponteiro de função

#endif