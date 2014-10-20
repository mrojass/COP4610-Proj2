#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

static int shuttle_init(void)
{
    printk(KERN_ALERT "Whatchu doin?\n");
    return 0;
}

static int shuttle_exit(void)
{
    printk(KERN_ALERT "Nuthin chillin at the Holiday Inn\n");
    return 0;
}

module_init(shuttle_init);
module_exit(shuttle_exit);
