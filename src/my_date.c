#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");

static int proc_show(struct seq_file *m, void *v){
	
	struct timeval tv;
	struct tm time;

	do_gettimeofday(&tv);

	time_to_tm(tv.tv_sec,0, &time);
		
	int year = time.tm_year + 1900;		
	int month = time.tm_mon + 1;
	seq_printf(m,"%d-%d-%d %d:%d:%d\n", year, month, time.tm_mday, (time.tm_hour-4), time.tm_min, time.tm_sec);
	
	return 0;
}

static int proc_open(struct inode *inode, struct file *file){
	return single_open(file, proc_show, NULL);
}

static const struct file_operations proc_fops={
	.owner = THIS_MODULE,
	.open = proc_open,
	.read = seq_read,
	.release = single_release,
};

static int __init date_proc_init(void){
	proc_create("currentdate", 0, NULL, &proc_fops);
	return 0;
}

static void __exit date_proc_exit(void){
	remove_proc_entry("currentdate", NULL);
}

module_init(date_proc_init);
module_exit(date_proc_exit);
