#include<stdio.h>
#include<unistd.h>

int main() {
  int fd[2];
  pipe(fd);
  int pid = fork();

  if(pid == -1){
    printf("write error");
    return 0;
  }

  int arr[] = {6,5,43,7,83,35,80};
  int size= sizeof(arr)/(arr[0]);

  if(pid > 0){
    printf("Parent process");
    for(int i =0 ; i < size; i++){
      for(j=0;j<size-1;j++){
        if(arr[j]<arr[j+1]){
          int temp = arr[j];
          arr[j+1] = temp;
        }
      }
    }

    close(fd[0]);
    write(fd[1], arr, sizeof(arr));

    for(int i = 0; i < size; i++){
      printf("%d",arr[i]);
    }
    printf("\n");
  }

else if(pid == 0){
  sleep(2);
  int arr1[7];
  printf("Child Process\n");
  close(fd[1]);
  read(fd[0], arr, sizeof(arr));

  for(int i= 0; i<7; i++){
    if(arr[i]%2 == 0){
      printf("%d ", arr[i]);
    }
  }
}
return 0;
}
