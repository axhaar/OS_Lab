#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int x=0;
	x=fork();
	if(x!=0)
	{
		sleep(2);
		printf("parent\n");
	}
	else
	{
		printf("child\n");
		exit(0);
	}
	return 0;
}
