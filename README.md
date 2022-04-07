# Linux-Semaphore  
Linux system contains a POSIX Semaphores library  
This is compiled by linking the compilation with -lpthread -lrt  
## Setup
```
sudo apt-get install gcc
```
## Compilation  
```
gcc producer.c -pthread -lrt -o producer  
gcc consumer.c -pthread -lrt -o consumer  
./producer & ./consumer &  
```
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

Note there is slight sync issue due to the speed and size of buffer, but no memory is being modified simultaneously 
## Example
```
Producer: initializer complete.
Producer: Created object 18
Consumer: Table has a values of 18 75
Producer: Created object 75
Consumer: Removing object 18
Consumer: Removing object 75
Producer: Created object 20
Consumer: Table now has values of 20 71
Producer: Created object 71
Consumer: Table has a values of 20 71
Consumer: Removing object 20
Consumer: Removing object 71
Producer: Created object 8
Consumer: Table now has values of 8 6
Producer: Created object 6
Consumer: Table has a values of 8 6
Consumer: Removing object 8
Consumer: Removing object 6
Producer: Created object 87
Consumer: Table now has values of 87 23
Producer: Created object 23
Consumer: Table has a values of 87 23
Consumer: Removing object 87
Consumer: Removing object 23
Producer: Created object 6
Consumer: Table now has values of 6 55
Producer: Created object 55
Consumer: Table has a values of 6 55
Consumer: Removing object 6
Consumer: Removing object 55
Producer: Created object 61
Consumer: Table now has values of 61 90
Producer: Created object 90
Consumer: Table has a values of 61 90
Consumer: Removing object 61
Consumer: Removing object 90
Consumer: Table now has values of 0 0
```
