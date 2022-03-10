# Linux-Semaphore
Linux system contains a POSIX Semaphores library
This is compiled by linking the compilation with -lpthread -lrt
Example:
$ gcc producer.cpp -pthread -lrt -o producer
$ gcc consumer.cpp -pthread -lrt -o consumer
$ ./producer & ./consumer &
