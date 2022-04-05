# Linux-Semaphore  
Linux system contains a POSIX Semaphores library  
This is compiled by linking the compilation with -lpthread -lrt  
Example:  
$ gcc producer -pthread -lrt -o producer  
$ gcc consumer -pthread -lrt -o consumer  
$ ./producer & ./consumer &  
## Files
Producer file 'adds' to the table by putting values into an array spot.
Consumer file 'removes' from the table by changing the array spots to a 0.
## Shared Memory
Shared Memory is done by using shm_open
Shared Memory is an array of size 3 (Last spot is technically a buffer)
## Shared Semaphore
Shared Semaphore is created by using sem_open to use a named semaphore.
## Solving the Producer and Consumer Problem
1. Producer creates a shared memory segment with shm_open, creating the array
2. Producer creates a named semaphore with sem_open
3. Consumer opens the shared memory segment with shm_open
4. Consumer opens the shared semaphore with shm_open
5. Producer starts by filling the shared table with numbers (non-zero)
6. The producer's critical stage is filling the table with non-zero integers
7. The consumer's critical stage is removing (filling) the table with zero
8. The program ends after a defined number of loops have been ran (8)
