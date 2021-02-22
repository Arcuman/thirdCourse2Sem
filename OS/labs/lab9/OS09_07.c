#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h> 
#include <stdbool.h>

int main(){

	printf("Bytes offset:");
	int s = 0;
	scanf("%d", &s);
	printf("\n");
	char buf[s];
	int fd;
	bool isWrite = true; 
	buf[s] = '\0'; 
	
	if((fd=open("/home/vadim/Документы/lab9/OS09_05.txt", O_RDONLY ))==-1) { 
	printf("Cannot open file.\n");
	exit(0);
	}
	do {
		if(lseek(fd, (long)s,1)==-1L){
			isWrite = false;
			printf("Seek Error\n");
		}
		if(read(fd, buf, s)==0) {
		        isWrite = false;
			printf("Read Error\n");
		}
		else {
			printf("%s-- \n", buf);
		}
	} while(isWrite);
	close(fd);
	return 0;
}
