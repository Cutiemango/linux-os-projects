#include <stdio.h>

#define SYSCALL_GETCPUNUM 441
#define TEST_ARRAY_SIZE 100000

int main() {
    unsigned int cpu_num = (unsigned int*) malloc(sizeof(unsigned int));
    int ret = syscall(SYSCALL_GETCPUNUM, &cpu_num);
    if (ret == 0) {
        printf("CPU number: %d\n", cpu_num);
    } else {
        printf("Something went wrong while executing the syscall!\n");
    }

    // bubble sort
    int arr[TEST_ARRAY_SIZE];
    for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
        arr[i] = TEST_ARRAY_SIZE - i;
    }
    for (int i = 0; i < TEST_ARRAY_SIZE; i++) {
        for (int j = 0; j < TEST_ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    
    return 0;
}