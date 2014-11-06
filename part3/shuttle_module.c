#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/export.h>
#include <linux/kthread.h>
#include <linux/init.h>

#include "syscalls.h"
#include "shuttle.h"

MODULE_LICENSE("Dual BSD/GPL");

// *******************
// Module Function
// 	Declarations
// *******************
extern int(*STUB_start_shuttle) (void);
extern int(*STUB_issue_request) (char passenger_type, int initial_terminal, int destination_terminal);
extern int(*STUB_stop_shuttle) (void);


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
// Global Struct
// ******************
struct Shuttle shuttle;
struct Terminal terminals[5];

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

	//int i = 0;
	//for(i=0; i < 5; i++){
	//	INIT_LIST_HEAD(&terminals[i].waitingPassengers);
	//}

	initShuttle(&shuttle);

	STUB_start_shuttle = &start_shuttle;
	STUB_stop_shuttle = &stop_shuttle;
	STUB_issue_request = &issue_request;

	return 0;
}

// ****************
// Shuttle Clean up
// ****************
static void shuttle_exit(void)
{
    STUB_start_shuttle = NULL;
    STUB_stop_shuttle = NULL;
    STUB_issue_request = NULL;
    proc_remove(entry);

}

module_init(shuttle_init);
module_exit(shuttle_exit);
