#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("WANGWEI");
MODULE_VERSION("1.0");

#include<linux/sched.h>
static void process_account(void)
{
    struct task_struct *start_task;
    unsigned long count = 0;

    start_task = &init_task;
    do
    {
        count ++;
		printk("%ld-%s,", start_task->pid, start_task->comm);
    }
    while((start_task = next_task(start_task)) != &init_task);
	printk("Total process is %ld\n", count);
}

static int __init kernel_init(void)
{
	process_account();
	return 0;
}

static void __exit kernel_exit(void)
{
    return;
}

module_init(kernel_init);
module_exit(kernel_exit);

