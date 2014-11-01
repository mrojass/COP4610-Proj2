#include <unistd.h>
#include <stdio.h>

int main(){

	int startResult = syscall(321);	//Calls start_shuttle system call. 
	printf("Start Shuttle: %d\n", startResult);
	
	//syscall(322);	//stop shuttle
	//syscall(323);	//issue request

	return 0;
}
