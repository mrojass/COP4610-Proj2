#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

int main(){

	int stopResult = syscall(322);	//Calls stop_shuttle system call. 
	printf("Stop Shuttle: %d\n", stopResult);

	return 0;
}
