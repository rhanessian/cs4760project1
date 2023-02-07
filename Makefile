.DEFAULT_GOAL
linuxcalls: oss.o worker.o
            gcc -o linuxcalls oss.o worker.o
            
oss.o: oss.c
        gcc -c oss.c
        
worker.o: worker.c
          gcc -c worker.c
          
.PHONY
clean:
      /bin/rm -f *.o *~ linuxcalls
