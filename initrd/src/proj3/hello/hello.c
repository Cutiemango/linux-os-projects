#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>

SYSCALL_DEFINE0(hello)
{
    printk("Hello Kernel!\n");
    return 0;
}

SYSCALL_DEFINE1(getcpunumber, unsigned int *, cpunum)
{
    int size = sizeof(unsigned int);
    unsigned int *num = (unsigned int *) kmalloc(size, GFP_KERNEL);
    *num = task_cpu(current);

    if (copy_to_user(cpunum, num, size)) {
        return -EFAULT;
    }
    return 0;
}

SYSCALL_DEFINE0(startcscount)
{
    current->context_switch_count = 0;
    return 0;
}

SYSCALL_DEFINE1(endcscount, unsigned int *, cscount)
{
    int size = sizeof(unsigned int);
    unsigned int *count = (unsigned int *) kmalloc(size, GFP_KERNEL);
    *count = current->context_switch_count;

    if (copy_to_user(cscount, count, size)) {
        return -EFAULT;
    }
    return 0;
}

