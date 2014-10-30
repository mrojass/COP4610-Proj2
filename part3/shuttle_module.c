#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");


// *******************
// Proc Open
// *******************
static proc_open(struct inode *inode, struct file *file){
    return single_open(file, proc_stats, NULL);
}

// ******************
// Prints  Stats
//  about the terminal
// ******************
static proc__stats(struct seq_file *m, void *v){
    seq_printf(m, "Dis Fo' Stats.\n");
    return 0;
}

// ******************
// File OP Struct
//*******************
static const struct file_operations proc_fops={
    .owner = THIS_MODULE,
    .open = proc_open,
    .read = seq_read,
    .release = single_release,
};

// 
// Shuttle Set up
//
static int shuttle_init(void)
{
    proc_create("terminal", 0, NULL, &proc_fops);
    return 0;
}

// 
//
static int shuttle_exit(void)
{
    proc_remove_entry("terminal", NULL);
    return 0;
}

/*
static int _init shuttle_proc_init(void){
    proc_create("terminal", 0, NULL, &proc_fops);
    return 0;
}

static void _exit shuttle_proc_exit(void){
    remove_proc_entry("terminal", NULL);
}
*/

module_init(shuttle_init);
module_exit(shuttle_exit);
