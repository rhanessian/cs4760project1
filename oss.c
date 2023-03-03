//Rebecca Hanessian
//CS4760
//Project 1: Linux System Calls-Skeleton Multiple Processes


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int counter = 0;

typedef struct {
    int proc;
    int simul;
    int iter;
} options_t;

void print_usage (const char* argmt){
	fprintf(stderr, "Usage: %s [-h] [-n proc] [-s simul] [-t iter]\n", argmt);
	fprintf(stderr, "	proc is the number of worker processes to launch\n");
	fprintf(stderr, "	simul is the number of processes that can run simultaneously\n");
	fprintf(stderr, "	iter is the number to be passed to the worker processes\n");
	fprintf(stderr, "Default proc is 15, default simul is 5, default iter is 10.\n");
}

void proc_exit(){
    counter--;
    printf("Handler Counter: %d\n", counter);
}

int main (int argc, char *argv[]){
	pid_t workerpid = 0;
	int i, j;
	
    char opt;
    options_t options;

    options.proc = 15;
    options.simul = 5;
    options.iter = 10;
	
	opterr = 0;

	while ((opt = getopt (argc, argv, "hn:s:t:")) != -1)
		switch (opt) {
            case 'h':
                print_usage (argv[0]);
                return (EXIT_SUCCESS);
			case 'n':
				options.proc = atoi(optarg);
				break;
			case 's':
				options.simul = atoi(optarg);
				break;
			case 't':
				options.iter = atoi(optarg);
				break;
			default:
				printf ("Invalid option %c\n", opt);
				print_usage (argv[0]);
				return (EXIT_FAILURE);		
		}
    
    signal (SIGCHLD, proc_exit);
	for (i = 0; i < options.proc; i++) {
        if (counter > options.simul){
            waitpid(workerpid,0,0);
            continue;
        }
        workerpid = fork();
        if (workerpid == 0){
            char *newargv[3];
            char iterBuf[20];
            sprintf(iterBuf, "%d",options.iter);
            newargv[0] = "./worker";
            newargv[1] = iterBuf;
            newargv[2] = NULL;
            printf("Exec Counter: %d\n", counter);
            execvp("./worker",newargv);
            exit(127);
        } else {
            counter++;
        }
    }
}
