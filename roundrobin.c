#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Process{
  int pid,at,bt,ct,tat,wt,rt,st;
};
int compare (const void *p1, const void *p2){
  int a=((struct Process *)p1)->at;
  int b=((struct Process *)p2)->at;
  if (a<b)
    return -1;
  else
    return 1;
}

void Dequeue(int *q,int n){
  for(int i=1;i<n;i++){
  q[i-1]=q[i];
  }
  q[n-1]=-1;
}

int main(){
  int n,qt;
  int swt=0,stat=0;
  float awt=0,atat=0;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  struct Process p[n];
  int queue[n];
  int rem[n];
  int nop=0,idle=0;
  for(int i=0;i<n;i++){
    printf("For Process %d ",i+1);
    p[i].pid=i+1;
    queue[i]=-1;
    printf("Enter the value of AT and BT: ");
    scanf("%d %d",&p[i].at,&p[i].bt);
  }
  qsort ((void *)p, n, sizeof(struct Process), compare);
  printf("Enter the Quantum Time: ");
  scanf("%d",&qt);
  for(int i=0;i<n;i++)
    rem[i]=p[i].bt;
  int r=0,t=p[0].at,c=0;
  queue[0]=0;
  r++;
  while(1){
    t++;
    for(int i=1;i<n;i++){
      if(p[i].at==t){
        queue[r++]=i;
      }
  }
  if(queue[0]==-1){
    idle++;
    continue;
  }
  int pos=queue[0];
  if(rem[pos]==p[pos].bt)
    p[pos].st=t-1;
  rem[pos]--;
  c++;
  if(rem[pos]==0){
    p[pos].ct=t;
    p[pos].tat=p[pos].ct-p[pos].at;
    p[pos].wt=p[pos].tat-p[pos].bt;
    p[pos].rt=p[pos].st-p[pos].at;
    c=0;
    nop++;
    Dequeue(queue,n);
    r--;
  }
  else if(qt==c){
    int temp=queue[0];
    Dequeue(queue,n);
    r--;
    queue[r++]=temp;
    c=0;
    }
    if(nop==n)
      break;
  }
  float cpu_ut=0,thro=0,cyclelen=0;
  cyclelen=p[n-1].ct-p[0].st;
  cpu_ut=((cyclelen-idle)/cyclelen)*100;
  thro=n/cyclelen;
  for(int i=0;i<n;i++){
    swt+=p[i].wt;
    stat+=p[i].tat;
  }
  awt=swt/(float)(n);
  atat=stat/(float)(n);
  printf("\nPId\tAT\tBT\tCT\tTAT\tWT\tRT\n");
  for(int i=0;i<n;i++){
    printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,
    p[i].tat,p[i].wt,p[i].rt);
  }
  printf("Sum of Waiting Time: %d\nAvergae Waiting Time:%6.3f\n",swt,awt);
  printf("Sum of Turn Around Time: %d\nAverage Turn Around Time:%6.3f\n",stat,atat);
  printf("\nCPU Utilization: %6.2f\nThroughput: %6.3f\n\n",cpu_ut,thro);
}
