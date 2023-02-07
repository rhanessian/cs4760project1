//Rebecca Hanessian
//CS4760
//Project 1: Linux System Calls-Skeleton Multiple Processes


void print_usage (const char* argmt){
	printf(stderr, "Usage: %s [-h] [-n proc] [-s simul] [-t iter]\n", \argmt);
	printf(stderr, "	proc is the number of worker processes to launch\n");
	printf(stderr, "	simul is the number of processes that can run simultaneously\n");
	printf(stderr, "	iter is the number to be passed to the worker processes\n");
	printf(stderr, "Default proc is 15, default simul is 5, default iter is 10.\n");
}

int main (int argc, const char *argv[]){
	pid_t workerpid = 0;
	int i, j, opt;
	int proc = 15, simul = 5, iter = 10;
	
	opterr = 0;

	while ((opt = getopt (argc, argv, "hn:s:t:")) != -1)
		switch (opt) {
			case 'n':
				proc = atoi(optarg);
				break;
			case 's':
				simul = atoi(optarg);
				break;
			case 't':
				iter = atoi(optarg);
				break;
			case 'h':
				print_usage (argv[0]);
				return (EXIT_SUCCESS);
			default:
				printf ("Invalid option %c\n", optopt);
				print_usage (argv[0]);
				return (EXIT_FAILURE);		}
}