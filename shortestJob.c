#include<stdio.h>

struct process
{
char pname[10];
int ex_time,wt_time,st_time,end_time;
}p[10],temp;

int main()
{
int n,i,j,k;
float avgwaittime=0.0,avgturnaroundtime=0.0;
float totalwaittime=0.0;
int totalexectime=0,totalturnaroundtime=0;

printf("\n enter the number of process");
scanf("%d",&n);
p[0].st_time=0;
p[0].wt_time=0;

for(i=0;i<n;i++)
    {
        printf("\n enter process name");
        scanf("%s",p[i].pname);
        printf("enter burst time");
        scanf("%d",&p[i].ex_time);
    }

for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                temp=p[i];p[i]=p[j];p[j]=temp;
            }
    }

p[0].wt_time=0;
p[0].st_time=0;
p[0].end_time=p[0].ex_time;
for(j=0;j<n;j++)
    {
        if(j>0)
            {
                p[j].wt_time=p[j-1].end_time;
                p[j].st_time=p[j-1].end_time;
                p[j].end_time=p[j].st_time+p[j].ex_time;
            }
            totalexectime+=p[j].ex_time;
            totalwaittime+=p[j].wt_time;
    }

avgwaittime=(float)totalwaittime/n;
totalturnaroundtime=totalexectime+totalwaittime;
avgturnaroundtime=(float)totalturnaroundtime/n;

printf("\n\nname brust start endwaittime\n");
for(k=0;k<n;k++)
printf("\n%s\t%d\t%d\t%d\t%d",p[k].pname,p[k].ex_time,p[k].st_time,p[k].end_time,p[k].wt_time);
printf("\naverage waiting time %f",avgwaittime);
printf("\n average turnaroundtime %f",avgturnaroundtime);

return 0;
}
