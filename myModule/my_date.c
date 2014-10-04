#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>
#include <linux/seq_file.h>
#include <linux/proc_fs.h>
MODULE_LICENSE("Dual BSD/GPL");

static int my_date_show(struct seq_file *m, void *v);
static int my_date_proc_open(struct inode *inode, struct file *file);
static int get_datetime(void);
static int __init my_date_init(void);
static void __exit my_date_exit(void);
static struct proc_dir_entry* vfile;

static int my_date_show(struct seq_file *m, void *v) {
	seq_printf(m, "Hello proc!\n");
	return 0;
}
static const struct file_operations mydate_seq_file_ops = {
	.owner = THIS_MODULE,
	.open = my_date_proc_open,
	.read = get_datetime
};


static int my_date_proc_open(struct inode *inode, struct file *file) {
	return single_open(file, my_date_show, NULL);
}

static int get_datetime(void) {
	return 0;
}

static int __init 
my_date_init(void){

	vfile = proc_create("currentdate", 0, NULL, &mydate_seq_file_ops);

	if (vfile == NULL)
		return  -ENOMEM;

//	getnstimeofday(struct timespec *tc);
	
/*	printk("TIME: %.2lu:%.2lu:%.2lu:%.6lu \r\n"
		(curr_tm.tv_sec / 3600) % (24),
		(curr_tm.tv_sec / 60) % (60),
		curr_tm.tv_sec % 60,
		curr_tm.tv_nsec / 1000); */

	printk(KERN_ALERT"WE INCHEAA BOY.\n");	
	return 0;
} 

static void __exit 
my_date_exit(void){
    
    printk(KERN_ALERT"WE OUTCHEA NIGGA!\n");
}

module_init(my_date_init);
module_exit(my_date_exit);
