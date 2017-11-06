#include<stdio.h>
void main()
{
int a[10],b[10],c[10],i,j,p,s,n,t=0,q[10];
clrscr();
printf("Enter the no. of process : ");
scanf("%d",&n);
printf("\nEnter the size of each process : ");
for(i=0;i<n;i++)
{ scanf("%d",&a[i]); q[i]=0;}
printf("Enter the size of memory: ");
scanf("%d",&s);
printf("Enter no. of partitions: ");
scanf("%d",&p);
for(i=0;i<p;i++)
b[i]=s/p;
for(i=0;i<n;i++)
{ if(b[i]>=a[i])
{ c[i]=b[i]-a[i]; q[i]=1; }
}
for(i=0;i<p;i++)
t+=c[i];
printf("\nProcess memory size process size fragmentation\n ");
for(i=0;i<p;i++)
{if(q[i]==1)printf("\n%d \t %d\t %d\t %d\t\n",i,b[i],a[i],c[i]);
}
}
