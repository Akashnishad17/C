/*SJF(Shortest Job First)*/
#include<stdio.h>
int main()
{
int bt[4],ct[4],tat[4],wt[4],i,j,temp,sum=0;
float avg_tat,avg_wt,sum1=0,sum2=0;
for(i=0;i<4;i++)
{
printf("Enter the burst time for %d program: ",i+1);
scanf("%d",&bt[i]);
sum=bt[i]+sum;
ct[i]=sum;
} 
for(i=0;i<4;i++)
{
tat[i]=ct[i];
wt[i]=tat[i]-bt[i];
}
for(i=0;i<4-1;i++)
{
for(j=i;j<4;j++)
{
if(bt[i]>bt[j])
{
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp=ct[i];
ct[i]=ct[j];
ct[j]=temp;

temp=tat[i];
tat[i]=tat[j];
tat[j]=temp;

temp=wt[i];
wt[i]=wt[j];
wt[j]=temp;
}
}
}
printf("P_no\tBT\tCT\tTAT\tWT\n");
for(i=0;i<4;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],ct[i],tat[i],wt[i]);
sum1=sum1+tat[i];
sum2=sum2+wt[i];
}
avg_tat=sum1/4;
avg_wt=sum2/4;
printf("Average of turn around time is %f\nAverage of waiting time is %f\n",avg_tat,avg_wt);
return 0;
}
