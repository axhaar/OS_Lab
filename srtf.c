#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid,at,bt,ct,wt,tat,rt,st;
};

void sort(struct Process *p,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].at>p[j].at){
                struct Process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

int FINDPOS(int t,int n,struct Process *p,int *rem){
    int minPos=-1,minVal=10000;
    for(int i=0;i<n;i++){
        if(rem[i]>0 && p[i].at<=t && rem[i]<minVal){
            minVal=rem[i];
            minPos=i;
        }
    }
    return minPos;
}

int main(){
    int n;
    scanf("%d",&n);
    
    struct Process p[n];
    int rem[n];
    
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i+1;
        p[i].st=-1;
        rem[i]=p[i].bt;
    }
    sort(p,n);
    int idealTime=0,cycleLength=0,totalTAT=0,totalWT=0,totalRT=0;
    float cpuUti=0,throughPut=0,avgTAT=0,avgWT=0,avgRT=0;
    
    int com=0,t=0;
    
    while(com<n){
        int pos=FINDPOS(t,n,p,rem);
        if(pos==-1){
            idealTime++;
            t++;
            continue;
        }
        if(p[pos].st==-1){
            p[pos].st=t;
        }
        rem[pos]--;
        
        if(rem[pos]==0){
            com++;
            p[pos].ct=t+1;
            p[pos].tat=p[pos].ct-p[pos].at;
            p[pos].wt=p[pos].tat-p[pos].bt;
            p[pos].rt=p[pos].st-p[pos].at;
            
            totalTAT+=p[pos].tat;
            totalWT+=p[pos].wt;
            totalRT+=p[pos].rt;
        }
        t++;
    }
    
    cycleLength=t;
    cpuUti=((float)(cycleLength-idealTime)/(float)cycleLength)*100;
    throughPut=(float)n/(float)cycleLength;
    avgTAT=(float)totalTAT/(float)n;
    avgWT=(float)totalWT/(float)n;
    avgRT=(float)totalRT/(float)n;
    
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("p-%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    
    printf("%f\n",avgTAT);
    printf("%f\n",avgWT);
    printf("%f\n",avgRT);
    printf("%f\n",cpuUti);
    printf("%f\n",throughPut);
    
}
