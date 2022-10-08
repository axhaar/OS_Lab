#include<stdio.h>
#include<unistd.h>
int main()
{
 	printf("Sonia Raghav \t 20012175 \n Section: J \t Roll Number: 57\n");
 	int n=10,sum=0,sum1=0;
 	int arr[] = {1,2,3,4,5,6,7,8,9,10};
 	int k=fork();
 	if(k>0)
 	{
 		for(int i=0;i<n;i++)
 		{
 			if(arr[i]%2==0)
 				sum+=arr[i];
 		}
 		printf("Even sum= %d\n",sum);
 	}
 	else
 	{
 		for(int i=0;i<n;i++)
 		{
 			if(arr[i]%2==1)
 			 	sum1+=arr[i];
 	        }
 	        printf("Odd sum= %d\n",sum1);
 	}
 	printf("\n");
 	return 0;
 } 
