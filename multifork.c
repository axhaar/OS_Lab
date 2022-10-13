#include<stdio.h>
#include<unistd.h>
int main()
{
	fork();
	printf("linux\n");
	fork();
	printf("unix\n");
	fork();
	printf("sonia\n");
	
	return 0;
}
