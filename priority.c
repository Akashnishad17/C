#include<stdio.h>
int main()
{
int p[5],pr[5],bt[5],ct[5],tat[5],wt[5],i,sum=0,j,temp;
float avg_tat,avg_wt,sum1=0,sum2=0;
for(i=0;i<5;i++)
{
printf("\nEnter the program ID: ");
scanf("%d",&p[i]);
printf("Enter the priority for Program ID %d: ",p[i]);
scanf("%d",&pr[i]);
printf("Enter the burst time for Program ID %d: ",p[i]);
scanf("%d",&bt[i]);
}
for(i=0;i<5-1;i++)
{
for(j=i;j<5;j++)
{
if(pr[i]>pr[j])
{
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp=pr[i];
pr[i]=pr[j];
pr[j]=temp;

temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
for(i=0;i<5;i++)
{
sum=bt[i]+sum;
ct[i]=sum;
tat[i]=ct[i];
wt[i]=tat[i]-bt[i];
}
printf("\nP_no\tPR\tBT\tCT\tTAT\tWT\n");
for(i=0;i<5;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],pr[i],bt[i],ct[i],tat[i],wt[i]);
sum1=sum1+tat[i];
sum2=sum2+wt[i];
}
avg_tat=sum1/5;
avg_wt=sum2/5;
printf("\nAverage of turn around time is %f\nAverage of waiting time is %f\n",avg_tat,avg_wt);
return 0;
}
