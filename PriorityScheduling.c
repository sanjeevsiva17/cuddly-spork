#include<stdio.h>

struct process
{
char pname[10];
int ex_time,wt_time,st_time,end_time,turn_time,priority;
}p[10],temp;

int main()
{
int n,i,j,k;
float avgwaittime=0.0,avgturnaroundtime=0.0;
float totalwaittime=0.0;
int totalexectime=0,totalturnaroundtime=0;

printf("\nenter number of process");
scanf("%d",&n);
p[0].st_time=0;
p[0].wt_time=0;

for(i=0;i<n;i++)
    {
        printf("\nenter process name");
        scanf("%s",p[i].pname);
        printf("\nenter process priority 0 with highest priority");
        scanf("%d",&p[i].priority);
        printf("enter burst time");
        scanf("%d",&p[i].ex_time);}

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        {
            if(p[i].priority<p[j].priority)
                {
                    temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
        }

    for(i=0;i<n;i++)
        {
            if(j==0)
                {
                    p[j].wt_time=0;
                    p[j].st_time=0;
                    p[j].end_time=p[j].ex_time;
                    p[j].turn_time=p[j].ex_time+p[j].wt_time;
                }
            if(j>0)
                {
                    p[j].wt_time=p[j-1].end_time;
                    p[j].st_time=p[j-1].end_time;
                    p[j].end_time=p[j].st_time+p[j].ex_time;
                    p[j].turn_time=p[j].ex_time+p[j].wt_time;
                }

            totalexectime+=p[j].ex_time;
            totalwaittime+=p[j].wt_time;
            totalturnaroundtime+=p[j].turn_time;
        }

avgwaittime=(float)totalwaittime/n;
avgturnaroundtime=(float)totalturnaroundtime/n;
printf("\n\nname burst start end waittime\n");
for(k=0;k<n;k++)
printf("\n%s\t%d\t%d\t%d\t%d\t%d",p[k].pname,p[k].ex_time,p[k].st_time,p[k].end_time,p[k].wt_time);
printf("\naveragewaitingtime%f",avgwaittime);
printf("\naverageturnaroundtime%f",avgturnaroundtime);

return 0;
}
