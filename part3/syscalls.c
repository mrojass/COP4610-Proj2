#include "syscalls.h"

int start_shuttle(void){
	printk(" start shuttle in syscalls..\n");
	return 0;
}

int stop_shuttle(void){
	printk("stop shuttle in syscalls..\n");
	return 0;
}

int issue_request(char passenger_type, int initial_terminal, int destination_terminal){

	printk("issue request in syscalls..\n");
	return 0;
}
