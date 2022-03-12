// Brandon Cossin
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define SEM_NAME "/semaphore_counter


int main(){
  sem_t *semaphore = sem_open (SEM_NAME, 0);
  int value;
  printf("starting the processes");
  sem_post(semaphore);
  printf("running");
  sem_wait(semaphore);
  printf("process 2 ran");
  sem_post(semaphore);
  return 0;
}
