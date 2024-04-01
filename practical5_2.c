#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main(){
  // writer code
  char buff[100]={"To kaise hain app log"};
  int shid;
  char *shadd;
  shid = shmget(2014, 2048, 0666 | IPC_CREAT);
  shadd=shmat(shid, NULL, 0);
  strcpy(shadd, buff);
  printf("Contents written on memory\n");

  return 0;
}



int main(){
  //reader code
  int shid= shmget(2014, 2048, 0666);
  char *shadd= shmadd(shid, NULL, 0);
  printf("Shared memory address: %d\n", shadd);
  printf("Contents are: %s\n", (char *)shadd);

  return 0;

}
