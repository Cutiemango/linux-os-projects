#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define SYSCALL_GETCPUNUM 441
#define SYSCALL_STARTCSCOUNT 442
#define SYSCALL_ENDCSCOUNT 443

#define ON  1
#define OFF 0
 
void main()
{
    unsigned int a;
    int b = 0;
    int running = ON;

    int ret = syscall(SYSCALL_STARTCSCOUNT);
    if (ret != 0) {
        printf("Something went wrong while executing the syscall!\n");
    }

    struct timeval start, cur;
    gettimeofday(&start, NULL);

    while (running) {
        sleep(0.01);
        printf("[%d ]", b++);

        gettimeofday(&cur, NULL);

        // if the program has run 2 minutes
        if (cur.tv_sec - start.tv_sec >= 120) { 
            running = OFF;
        }
    }

    int ret = syscall(SYSCALL_ENDCSCOUNT, &a);
    if (ret != 0) {
        printf("Something went wrong while executing the syscall!\n");
    }

    printf("\nDuring the past 2 minutes the process makes %d times process switches.\n", a);
}