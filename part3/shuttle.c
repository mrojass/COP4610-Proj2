#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/export.h>

int(*STUB_start_shuttle)(void) = NULL;
int(*STUB_stop_shuttle)(void) = NULL;
int(*STUB_issue_request)(void) = NULL;

EXPORT_SYMBOL(STUB_start_shuttle);
EXPORT_SYMBOL(STUB_stop_shuttle);
EXPORT_SYMBOL(STUB_issue_request);

asmlinkage int start_shuttle(void){
    if(STUB_start_shuttle)
        STUB_start_shuttle();
    else
        printk(KERN_ALERT "Print something..");
    
    return 0;
}

asmlinkage int stop_shuttle(void){
    if(STUB_stop_shuttle)
        STUB_stop_shuttle();
    else
        printk(KERN_ALERT "Print something else..");

    return 0;
}

asmlinkage int issue_request(void){
    if(STUB_issue_request)
        STUB_issue_request();
    else
        printk(KERN_ALERT "Meh.");
    
    return 0;
}
