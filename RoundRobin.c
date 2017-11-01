#include<stdio.h>

struct process
{
char PName[10];
int ex_time,wt_time,st_time,end_time,turn_time;
int rem_time,completed_time;
}p[10],temp;

// ex_time is burst time,
// wt_time is waiting time ,
// st_time is start time
// end_time is ending time
// turn_time is turn around time


int quant_time; // time quantum

main()
{
int n,i,j,k;
float avgWaitTime=0.0,avgTurnAroundTime=0.0;
float totalWaitTime=0.0;

int totalExecTime=0,totalTurnAroundTime=0;
int fs,fe;


printf("\nEnter number of process");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("\nEnter process name");
    scanf("%s",p[i].PName);
    printf("Enter Burst time ");
    scanf("%d",&p[i].ex_time);
    p[i].rem_time=p[i].ex_time;
    p[i].completed_time=0;
}


printf("\nEnter quantum time ");
scanf("%d",&quant_time);

printf("\n name start end busrt rem compl");
/* for first process start and the wait time to be 0 */
j=0;

fs=p[j].st_time=0;
p[j].wt_time=0;

if(p[j].ex_time>quant_time)
    {
        p[j].end_time=quant_time;
        p[j].completed_time=quant_time;
    }
else
    {
        p[j].end_time=p[j].ex_time;
        p[j].completed_time=p[j].ex_time;
        p[j].wt_time=p[j].end_time-p[j].rem_time;
        p[j].turn_time=p[j].wt_time+p[j].ex_time;
    }

p[j].rem_time=p[j].ex_time-p[j].completed_time;

printf("\n%s\t%d\t%d\t%d\t%d\t%d",p[j].PName,p[j].st_time,p[j].end_time,p[j].ex_time,p[j].rem_time,p[j].completed_time);
fe=p[j].end_time;
j++;


while(j<n)
    {
        p[j].st_time=fe;
        if(p[j].rem_time>quant_time)
            {
                p[j].end_time=p[j].st_time+quant_time;
                p[j].rem_time-=quant_time;
                p[j].completed_time+=quant_time;
                fe+=quant_time;
                printf("\n%s\t%d\t%d\t%d\t%d\t%d",p[j].PName,p[j].st_time,p[j].end_time,p[j].ex_time,
                p[j].rem_time,p[j].completed_time);
            }
        else if(p[j].rem_time>0)
            {
                p[j].end_time=p[j].st_time+p[j].rem_time;
                p[j].wt_time=fe-p[j].completed_time;
                p[j].completed_time+=p[j].rem_time;
                p[j].turn_time=p[j].wt_time+p[j].ex_time;
                fe+=p[j].rem_time;p[j].rem_time=0;
                printf("\n%s\t%d\t%d\t%d\t%d\t%d",p[j].PName,p[j].st_time,p[j].end_time,p[j].ex_time,
                p[j].rem_time,p[j].completed_time);
            }
        j++;
        if(j==n)
            {
                for(k=0;k<n;k++)
                {
                    if(p[k].rem_time>0) /*break for the inner for loop */
                        {
                            j=k;
                            break;
                        }
                }
                if(k>n) /* breaks from the outer while loop */
                break;
            }
    }


printf("\n Process Name Waiting Time Turn Around Time");
for(i=0;i<n;i++)
    {
        printf("\n%s\t\t%d\t\t%d",p[i].PName,p[i].wt_time,p[i].turn_time);
        totalWaitTime+=p[i].wt_time;
        totalTurnAroundTime+=p[i].turn_time;
    }
avgWaitTime=(float)totalWaitTime/n;
avgTurnAroundTime=(float)totalTurnAroundTime/n;
printf("\nAverage waiting time %f",avgWaitTime);
printf("\nAverage turn around time %f",avgTurnAroundTime);
}
