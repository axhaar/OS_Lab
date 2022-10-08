#include<stdio.h>
#include<unistd.h>

int main()
{
 	printf("Sonia Raghav \t 20012175 \n Section: J \t Roll Number: 57\n");
 	pid_t pid=fork();
 	
 	if(pid>0)
 	{
 	  printf("parent process with id = %d with child id =%d\n",getppid(),getpid());
 	}
 	else if(pid==0)
 	{
 	 sleep(9);
 	  printf("child process with id = %d with parent id=%d\n",getppid(),getpid());
 	}
 	return 0;
}
