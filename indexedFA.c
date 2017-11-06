#include<stdio.h>

int main()
{
char a[10];
int i,ib,cib[10],k[50],cont;
for(i=0;i<50;i++)
k[i]=-1;
printf("\n enter the file name:");
scanf("%s",a);
printf("\n index block:");
scanf("%d",&ib);
k[ib]=ib;
for(i=1;i<=5;i++)
{
printf("\n enter the child index block %d:",i);
scanf("%d",&cib[i]);
if(k[cib[i]]!=-1)
{
printf("\n block already allocated");
i--;
continue;
}
k[cib[i]]!=cib[i];
}
printf("\n the list of files\t index block\n");
printf("%s\t\t %d",a,ib);
printf("\n");
for(i=1;i<=5;i++)
{printf("%d\t\t",cib[i]);
}
printf("\n");
return 0;
}
