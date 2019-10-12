#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int bt[n],ct[n],tat[n],wt[n],sum=0,total=0,i,temp[n];
    float sum1=0,sum2=0,avg_tat,avg_wt;
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time for process %d: ",i+1);
        scanf("%d",&bt[i]);
        total+=bt[i];
    }
    printf("Enter time quanta: ");
    scanf("%d",&t);
    while(total>0)
    {
        for(i=0;i<n;i++)
        {
            temp[i]=bt[i];
            if(temp[i]>0)
            {
                temp[i]=bt[i]-t;
                total-=t;
            }
            if(temp[i]<0)
            {
                ct[i]=
            }
        }
    }
}
