#include<stdio.h>
#include<stdlib.h>
struct info{
	int max[100],allocated[100],need[100];
}; 
void input(struct info *p,int *a,int n,int r)
{
	for(int i=0;i<n;i++)
	{
		printf("For Process %d Enter the Maximum Need: ",i+1);
		for(int j=0;j<r;j++)
			scanf("%d",&p[i].max[j]);
		
		printf("Enter the Allocated Resources: ");
		for(int j=0;j<r;j++)
		{
			scanf("%d",&p[i].allocated[j]);
			
			p[i].need[j]=p[i].max[j]-p[i].allocated[j];
		} 
	}
	printf("\nEnter the Available Resources: ");
	for(int i=0;i<r;i++)
		scanf("%d",&a[i]);
	printf("\n");
} 
void print(struct info *p,int *a,int n,int r)
{
	printf("ProcessID\tMaximum \tAllocated \tNeed\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t\t",i+1);
		for(int j=0;j<r;j++)
		{
			printf("%d ",p[i].max[j]);
		}
		printf("\t\t");
		for(int j=0;j<r;j++)
		{
			printf("%d ",p[i].allocated[j]);
		}
		printf("\t\t");
		for(int j=0;j<r;j++)
		{
			printf("%d ",p[i].need[j]);
		}
		
		printf("\n\n");
	}
} 
int main()
{ 
	int n,r,flag=0;
	printf("Enter the number of Processes: ");
	scanf("%d",&n);
	
	printf("Enter the number of Resources: ");
	scanf("%d",&r);
	 
	int avail[r];
	struct info p[n];
	input(p,avail,n,r);
	
	int fin[n],seq[n],nop=0;
	for(int i=0;i<n;i++){
		fin[i]=0;
		seq[i]=-1;
	}
	while(1)
	{
		for(int i=0;i<n;i++)
		{
			if(fin[i]!=1)
			{
				int j=0;
				for(;j<r;j++)
				{
					if(p[i].need[j]>avail[j])
					{
						flag=1;
						break;
					}
          else flag=0;
				}
				if(j==r)
				{
					for(int j=0;j<r;j++)
					{
						avail[j]+=p[i].allocated[j];
					} 
					fin[i]=1;
					seq[nop++]=i+1;
				} 
			}
		} 
		if(nop==n||flag==1)
			break;
	}
	for(int i=0;i<n;i++)
	{
		if(fin[i]==0)
		{
			printf("Not a Safe Sequencing...Deadlock Present\n");
			exit(0);
		}
	} 
	print(p,avail,n,r); 
	printf("No Deadlock Present....Safe Sequencing!!\n");
	printf("Process Sequence is: ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",seq[i]);
	}
	printf("\n");
	return 0;
}
