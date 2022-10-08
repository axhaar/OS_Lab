#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
 	printf("Sonia Raghav \t 20012175 \n Section: J \t Roll Number: 57\n");
 	pid_t pid=fork();
 	
 	//Parent Process
 	if(pid>0)
 	{
 	  printf("In Parent Process\n");
 	  sleep(15);
 	}
 	
 	//Child Process
 	else 
 	{
 	  exit(0);
 	}
 	return 0;
}
