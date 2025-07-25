#include<stdio.h>
void main()
{
int i,j,pno[10],prior[10],bt[10],n,wt[10],wl=0,tl=0,s,tt[10];
float aw,at;
printf("enter the no of processes:");
scanf("%d",&n);
for(i=0;i<n;i++);
{
printf("the process %d:\n ",i+1);
printf("enter the burst time of processes:");
scanf("%d",&bt[i]);
printf("enter the priority of processes%d:",i+1);
scanf("%d",&prior[i]);
pno[i]=i+1;
}
for(i=0;i<n;i++)
{
for(j=0;j<n;i++)
{
if(prior[i]<prior[j])
{
s=prior[i];
prior[i]=prior[j];
prior[j]=s;
s=bt[i];
bt[i]=bt[j];
bt[j]=s;
s=pno[i];
pno[i]=pno[j];
pno[j]=s;
}
}
}
for(i=0;i<n;i++)
{
wt[0]=0;
tt[0]=bt[0];
wt[i+1]=bt[i]+wt[i];
tt[i+1]=tt[i]+bt[i+1];
wl=wl+wt[i];
tl=tl+tt[i];
aw=wl/n;
at=tl/n;
}
printf("\n job\t bt\t wt\t tat\t sprior\n"); 
for(i=0;i<n;i++)
printf("%d\t%d\t%d\t%d\t%d\n",pno[i],bt[i],wt[i],tt[i],prior[i]);
printf("aw=%f\n,at=%f\n",aw, at);
}
