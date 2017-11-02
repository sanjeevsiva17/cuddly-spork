#include<stdio.h>

struct process
{
char pName[10];
int ex_time,wt_time,st_time,end_time;
}p[10];

int main()
{
int n,i,j,k;
float avgwaittime=0.0,avgTurnAroundTime=0.0;
float totalWaitTime=0.0;
int totalExecTime=0,totalTurnAroundTime=0;

printf("\n enter number of process");
scanf("%d",&n);
p[0].st_time=0;
p[0].wt_time=0;

for(i=0;i<n;i++)
    {
        printf("\n enter process name");scanf("%s",p[i].pName);
        printf("enter Burst time");
        scanf("%d",&p[i].ex_time);

        if(i==0)
            p[i].end_time=p[i].ex_time;
        else
            {
                p[i].wt_time=p[i-1].end_time;
                p[i].st_time=p[i-1].end_time;
                p[i].end_time=p[i].st_time+p[i].ex_time;
            }
    }

for(j=0;j<n;j++)
    {
        totalExecTime+=p[j].ex_time;
        totalWaitTime+=p[j].wt_time;
    }

totalTurnAroundTime=totalExecTime+totalWaitTime;
avgwaittime=(float)totalWaitTime/n;
avgTurnAroundTime=(float)totalTurnAroundTime/n;

printf("\n\n Name Burst Start End Wait Time\n");

for(k=0;k<n;k++)
    printf("\n%s \t%d \t%d \t%d \t%d",p[k].pName,p[k].ex_time,p[k].st_time,p[k].end_time,p[k].wt_time);

    printf("\nAverage Waiting Time %f",avgwaittime);
printf("\n Average Turn Around Time %f",avgTurnAroundTime);

return 0;
}
