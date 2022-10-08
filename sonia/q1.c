#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Sonia Raghav \t 20012175 \n Section: J \t Roll Number: 57\n");
	fork();
	printf("Process ID: %d\n", getpid());
	return 0;
}
