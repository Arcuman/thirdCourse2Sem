#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
  char buf[10000];
  
  int in = open("/home/diana/lw9/os_09_05.txt", O_RDONLY);
  if(in == -1)
  	printf("%d", in);
  int n = read(in, buf, 10000);
  if(n == -1)
  	printf("%d", n);
  int countRow = 0;
  for(int i = 0; i < n; i++){
  	if(buf[i] == '\n')
  	   countRow++;
  	
  }
  printf("%d", countRow);
  printf("%c", '\n');
  
  exit(0);
}
