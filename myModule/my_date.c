#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>

MODULE_LICENSE("Dual BSD/GPL");

static int time_init(void){

	getnstimeofday(struct timespec *tc);
	
	printk("TIME: %.2lu:%.2lu:%.2lu:%.6lu \r\n",
		(curr_tm.tv_sec / 3600) % (24),
		(curr_tm.tv_sec / 60) % (60),
		curr_tm.tv_sec % 60,
		curr_tm.tv_nsec / 1000);

	printk(KERN_ALERT"WE INCHEAA BOY.\n");	
	return 0;
} 

static void time_exit(void){
    
    printk(KERN_ALERT"WE OUTCHEA NIGGA!\n");
}

module_init(time_init);
module_exit(time_exit);
