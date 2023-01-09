#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SYSCALL_GETCPUNUM 441

int main() {
    printf("PID: %d\n", getpid());

    unsigned int cpu_num;
    int ret = syscall(SYSCALL_GETCPUNUM, &cpu_num);
    if (ret == 0) {
        printf("CPU number: %d\n", cpu_num);
    } else {
        printf("Something went wrong while executing the syscall!\n");
    }

    while (1) {}
    
    return 0;
}