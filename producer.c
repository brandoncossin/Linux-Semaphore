#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define SEM_NAME "/semaphore_counter

int main(){
  sem_t *semaphore = sem_open (SEM_NAME, O_CREAT, 0644, 0);
  int value;
  sem_wait(semaphore);
  printf("process 1 ran");
  sem_post(semaphore);
  return 0;
}
