//Rebecca Hanessian
//CS4760
//Project 1: Linux System Calls-Skeleton Multiple Processes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, const char *argv[]){
	int iterations = atoi(argv[1]);
	int i, j;
	int pid = getpid();
	int ppid = getppid();
	for (j = 0; j < iterations; j++){
		fprintf(stderr, "WORKER PID: %d PPID: %d Iteration %d before sleeping\n", pid, ppid, j+1);
		sleep(1);
		fprintf(stderr, "WORKER PID: %d PPID: %d Iteration %d after sleeping\n", pid, ppid, j+1);
	}
	
}