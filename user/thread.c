#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "user/thread.h"

int 
thread_create(void (*start_routine)(void *, void*), void *arg1, void *arg2){
    void *stack = malloc(4096);
    if (stack == 0) {
        printf("thread_create: malloc failed\n");
        return -1;
    }   
    return clone(start_routine, arg1, arg2, stack);
}

int
thread_join(void){
    void *stack;
    int pid = join(&stack);
    free(stack);
    printf("thread_join: %d\n", pid);
    return pid;
}