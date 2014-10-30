#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

// *******************
// Module Function
// 	Declarations
// *******************
static int shuttle_init(void);
static int shuttle_exit(void);

// *******************
// Proc Entry 
// 	Declaration
// *******************
static struct proc_dir_entry * entry;

// *******************
// Function 
// 	Declarations
// *******************
static int proc_open(struct inode *inode, struct file *file);
static int proc_stats(struct seq_file *m, void *v);

// ******************
// File OP Struct
//*******************
static const struct file_operations proc_fops={
    .owner = THIS_MODULE,
    .open = proc_open,
    .read = seq_read,
    .release = single_release,
};

// *******************
// Proc Open
// *******************
static int proc_open(struct inode *inode, struct file *file){
    return single_open(file, proc_stats, NULL);
}

// ******************
// Prints  Stats
//  about the terminal
// ******************
static int proc_stats(struct seq_file *m, void *v){
    seq_printf(m, "Dis Fo' Stats.\n");
    return 0;
}

// ************** 
// Shuttle Set up
// **************
static int shuttle_init(void)
{
    entry = proc_create("terminal", 0, NULL, &proc_fops);
    if(entry == NULL)
	return -ENOMEM;

	return 0;
}

// ****************
// Shuttle Clean up
// ****************
static int shuttle_exit(void)
{
    proc_remove(entry);
    return 0;
}

module_init(shuttle_init);
module_exit(shuttle_exit);
