// Brandon Cossin
// Operating Systems Assignment 1
// Consumer file

#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define SEM_NAME "/semaphore_counter"
#define SHM_NAME "/shared_table"
int main(){
  //shared memory creation
  struct table_name {
    int buf[3];
  };
  void *addr;
  int size = 4096;
  int sd = shm_unlink(SHM_NAME);
  int fd = shm_open(SHM_NAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
  int fres;
  fres = ftruncate(fd, size);
  if(fres == -1){
    printf("Consumer: ftruncate error");
    shm_unlink(SHM_NAME);
    return 1;
  }
  struct table_name *tble = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd, 0);
  sem_t *semaphore = sem_open (SEM_NAME, 0);
  int value;
  int LOOP_TIMES = 6;
  while(LOOP_TIMES > 0){
    sem_wait(semaphore);
    if(tble->buf[0] != 0 & tble->buf[1] != 0){
      printf("Consumer: Table has a values of ");
      printf("%i", tble->buf[0]);
      printf(" ");
      printf("%i", tble->buf[1]);
      printf("\nConsumer: Removing object ");
      printf("%i", tble->buf[0]);
      printf("\nConsumer: Removing object ");
      printf("%i", tble->buf[1]);
      tble->buf[0] = 0;
      tble->buf[1] = 0;
      printf("\nConsumer: Table now has values of ");
      printf("%i", tble->buf[0]);
      printf(" ");
      printf("%i", tble->buf[1]);
      printf(" \n");
      --LOOP_TIMES;
    }
    sem_post(semaphore);
  }
  sem_close(semaphore);
  sem_unlink(SEM_NAME);
  shm_unlink(SHM_NAME);
  return 0;
}
