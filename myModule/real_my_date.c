#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>
#include <linux/seq_file.h>
#include <linux/proc_fs.h>
MODULE_LICENSE("Dual BSD/GPL");

static int my_date_show(struct seq_file *m, void *v);
static int my_date_proc_open(struct inode *inode, struct file *file);
static int get_datetime(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data);
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

int procfile_write(struct file *file, const char *buffer, unsigned long count, void *data){
	//procfs_buffer_size = count;
	return 0;
}


static int get_datetime(char *buffer, char **buffer_location, off_t offset, int buffer_length, int	*eof, void *data) 
{
	
/*	struct timespec curr_tm;
	getnstimeofday(&curr_tm);
		
	printk("TIME: %.2lu:%.2lu:%.2lu:%.6lu \r\n",
		(curr_tm.tv_sec / 3600) % (24),
		(curr_tm.tv_sec / 60) % (60),
		curr_tm.tv_sec % 60,
		curr_tm.tv_nsec / 1000);
*/

	unsigned long get_time;
	int sec, hr, min, tmp1, tmp2, ret;
	struct timeval tv;
	struct tm time;
	
	do_gettimeofday(&tv);
	/*get_time = tv.tv_sec;
	sec = get_time / 60;
	tmp1 = get_time / 60;
	min = tmp1 % 60;
	tmp2 = tmp1 / 60;
	hr = tmp2 % 24;
			*/
	
	time_to_tm(tv.tv_sec, 0, &time);
	printk("%d:%d:%d\n", time.tm_hour, time.tm_min, time.tm_sec); 
	printk(KERN_INFO "procfile_read (/proc/currentdate) called\n");

/*	if (offset > 0) {
		ret = 0;
	} else {
		ret = sprintf(buffer, "The current time be: %d : %d : %d\n", hr, min, sec);
	
//		*offset = ret;
	}

//	*eof = 1; 
*/
	ret = sprintf(buffer, "%d:%d:%d\n", time.tm_hour, time.tm_min, time.tm_sec);
	return ret;
}

static int __init
my_date_init(void){

	vfile = proc_create("currentdate", 0, NULL, &mydate_seq_file_ops);

	if (vfile == NULL)
		return  -ENOMEM;

//	getnstimeofday(struct timespec *tc);
	
/*	printk("TIME: %.2lu:%.2lu:%.2lu:%.6lu \r\n"
		(curr_tm.tv_sec / 3i600) % (24),
		(curr_tm.tv_sec / 60) % (60),
		curr_tm.tv_sec % 60,
		curr_tm.tv_nsec / 1000); */

	printk(KERN_ALERT"WE INCHEAA BOY.\n");	
	return 0;
} 

static void __exit 
my_date_exit(void){
    remove_proc_entry("my_date", NULL);    
    printk(KERN_ALERT"WE OUTCHEA NIGGA!\n");
}

module_init(my_date_init);
module_exit(my_date_exit);
