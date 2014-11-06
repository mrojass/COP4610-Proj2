#include "syscalls.h"

extern struct Shuttle shuttle;

int start_shuttle(void){
	int ret = 0;

	if(shuttle.status == OFFLINE)
	{
		printk(KERN_DEBUG "Starting Shuttle.\n");		
	}else
		ret = 1;	//Shuttle Already Started.
	
	return ret;
}

int stop_shuttle(void){
	int ret = 0;
	
	printk("Stopping Shuttle.\n");

	if(shuttle.status == OFFLINE || shuttle.status == DEACTIVATING)
		ret = 1;

	return ret;
}

int issue_request(char passenger_type, int initial_terminal, int destination_terminal){

	printk("issue request in syscalls..\n");
	return 0;
}
