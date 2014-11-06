#include "shuttle.h"

extern struct Shuttle shuttle;

// ********************************************
// Initialize Shuttle.
// ********************************************
void initShuttle(struct Shuttle * shuttle){

	shuttle->currentTerminal = 3;
	shuttle->status = PARKED;
	shuttle->passengerCount[0] = 0;
	shuttle->passengerCount[1] = 0;
	shuttle->passengerCount[2] = 0;
}

// ********************************************
// Run starts the shuttle.
//  If already started, it takes in passengers
//   until it has been stopped.
// ********************************************

void loadPassengers();
void unloadPassengers();
int main_run(void){

	//While shuttle is running
	//	if passenger want to get off at current terminal
	//		unload
	//	if passenger want to get on at current terminal AND there is space
	//		Load passenger
	// 	move to next terminal
	//end while	

	//NOTE: Check Project2-4 powerpoint.

	return 0;
}
