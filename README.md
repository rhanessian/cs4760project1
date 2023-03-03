# cs4760project1
# Linux System Calls-SKeleton Multiple Processes
# Rebecca Hanessian

This program utlizes a master file and a worker file. The master forks the worker/n
a given or default number of iterations of a given or default number of processes./n
The number of simultaneous processes is also given or a default value is used./n
The master forks the worker, which prints a message, waits, and then prints/n 
another message. The usage is as follows:/n

Usage: ./oss [-h] [-n proc] [-s simul] [-t iter]/n
        proc is the number of worker processes to launch/n
        simul is the number of processes that can run simultaneously/n
        iter is the number to be passed to the worker processes/n
Default proc is 15, default simul is 5, default iter is 10.
