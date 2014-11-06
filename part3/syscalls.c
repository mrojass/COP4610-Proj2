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

	/*
	if (shuttle->currentTerminal == destination_terminal)
	{
		return 0;
	}
	else {
		struct Passenger* passenger;
		passenger = kmalloc(sizeof(*passenger), GFP_KERNEL);
		passenger_type type;
		passenger->initial_terminal = initial_terminal;
		passenger->destination_terminal = destination_terminal;
		switch(passenger_type)
		{
			case 'C':
				type = CHILD;
			case 'A':
				type = ADULT;
			case 'L'
				type = LUGGAGE;
		}
		passenger->passenger_type = type;

		list_add_tail(&passenger->list, &terminal_list[initial_terminal]->waitingPassengers); 
	}
	*/
	return 0;
}
