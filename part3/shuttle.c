#include "shuttle.h"

extern struct Shuttle shuttle;

static int loadPassengers();
static int unloadPassengers();

void clearShuttle(struct Shuttle * shuttle);

// ********************************************
// Run starts the shuttle.
//  If already started, it takes in passengers
//   until it has been stopped.
// ********************************************
int main_run(){

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

static int loadPassengers(){

	return 0;
}

static int unloadPassengers(){
	
	return 0;
}
