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

static proc_open(struct inode *inode, struct file *file){
    return single_open(file, proc_show, NULL);
}

static const struct file_operations proc_fops={
    .owner = THIS_MODULE,
    .open = proc_open,
    .read = seq_read,
    .release = single_release,
};

static int _init date_proc_init(void){
    proc_create("terminal", 0, NULL, &proc_fops);
    return 0;
}

static void _exit date_proc_exit(void){
    remove_proc_entry("terminal", NULL);
}

module_init(shuttle_init);
module_exit(shuttle_exit);
