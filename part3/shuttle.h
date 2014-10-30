#pragma once

#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/list.h>
#include <linux/list_sort.h>
#include <linux/time.h>

// *****************
// Enum Declarations
// *****************
enum shuttleStatus { OFFLINE=0, DEACTIVATING=1, MOVING=2, PARKED=3};
enum passengerType { CHILD=0, ADULT=1, LUGGAGE=2 };

// **************
// Shuttle Struct
// **************
struct Shuttle{
	// Tracks Terminal Location
	int currentTerminal;
	int destinationTerminal;

	// 0=Child, 1=Adult, 2=Adult&Luggage
	int passengerCount[3]; 
	int passengerDelivered[3];

	//Shuttle timing
	struct timespec timeStarted;
	struct timespec timeStopped;

	enum shuttleStatus status;
};

// *************
// Passenger
//  Struct
// *************
struct Passenger{
	int initialTerminal;
	int destinationTerminal;
	
	//Doule Linked List
	struct list_head list;

	//Enum
	enum passengerType type;
};


// **********************
// Function Declarations
// **********************
int main_run(); 	//Main functionality.



