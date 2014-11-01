#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/linkage.h>
#include <linux/export.h>

int(*STUB_start_shuttle)(void) = NULL;
int(*STUB_stop_shuttle)(void) = NULL;
int(*STUB_issue_request)(char passenger_type, int initial_terminal, int destination_terminal) = NULL;

EXPORT_SYMBOL(STUB_start_shuttle);
EXPORT_SYMBOL(STUB_stop_shuttle);
EXPORT_SYMBOL(STUB_issue_request);

asmlinkage int sys_start_shuttle(void){
    if(STUB_start_shuttle)
        return STUB_start_shuttle();
    else
        printk(KERN_ALERT "Error: Can't start shuttle.");
    
    return -ENOSYS;
}

asmlinkage int sys_stop_shuttle(void){
    if(STUB_stop_shuttle)
        return STUB_stop_shuttle();
    else
        printk(KERN_ALERT "Error: Can't stop shuttle.");

    return -ENOSYS;
}

asmlinkage int sys_issue_request(char passenger_type, int initial_terminal, int destination_terminal){
    if(STUB_issue_request)
        return STUB_issue_request(passenger_type, initial_terminal, destination_terminal);
    else
        printk(KERN_ALERT "Error: There was a problem with Issue_Request.");
    
    return -ENOSYS;
}
