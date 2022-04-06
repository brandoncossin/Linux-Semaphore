// Brandon Cossin
// Operating System Assignment 1
// Producer file

#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SEM_NAME "/semaphore_counter"
#define SHM_NAME "/shared_table"
int main(){
  //shared memory creation
  struct table_name {
    int buf[3];
  };
  void *addr;
  int size = 4096;
  int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  struct table_name *tble = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd, 0);
  //semaphore logic
  sem_t *semaphore = sem_open (SEM_NAME, O_CREAT, 0644, 0);
  int value;
  tble->buf[0] = 0;
  tble->buf[1] = 0;
  printf("\nProducer: initializer complete.\n");
  srand(time(0));
  int LOOP_TIMES = 6;
  sem_post(semaphore);
  while(LOOP_TIMES > 0){
    sem_wait(semaphore);
    if(tble->buf[0] == 0 & tble->buf[1] == 0){
      int tmp1 = (rand() % 9) + 1;
      tble->buf[0] = tmp1;
      int tmp2 = (rand() % 9) + 1;
      tble->buf[1] = tmp2;
      printf("Producer: Created object %d", tmp1);
      printf("\nProducer: Created object %d", tmp2);
      printf("\n");
      --LOOP_TIMES;
    }
    //const char num[50] = "44";
    //memcpy(addr, num, strlen(num)+1);
    sem_post(semaphore);
  }
  return 0;
}
