#ifndef KERNEL_H_
#define KERNEL_H_

// código de retorno
#define SUCCESS 0
#define FAIL 1
#define REPEAT 2

// declaração de ponteiro de função
typedef char (*ptrFunc)(int);

// definição da estrutura de um processo
typedef struct {
    ptrFunc func;
}process;

// protótipo das funções do kernel
char kernelInit(void);
char kernelAddProc(process* newProc);
void kernelLoop(void); //declaração de ponteiro de função

#endif