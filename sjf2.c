#include<stdio.h>
void sort(int bt[],int at[],int p[],int q, int r);
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int p[n],bt[n],at[n],i,j=0,k,sum=0,ct[n],tat[n],wt[n];
    float sum1=0,sum2=0,avg_tat,avg_wt;
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("\nEnter the burst time for program %d: ",i+1);
        scanf("%d",&bt[i]);
        printf("Enter the arrival time for program %d: ",i+1);
        scanf("%d",&at[i]);
    }
    i=1;
    sum+=bt[j]+at[j];
    ct[j]=sum;
    while(j<n-1)
    {
        while(at[i]-ct[j]<=0 && i<n-1)
        {
            i++;
        }
    j++;
    sort(bt,at,p,j,i+1);
    sum=sum+bt[j];
    ct[j]=sum;
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        sum1+=tat[i];
        sum2+=wt[i];
    }
    avg_tat=sum1/n;
    avg_wt=sum2/n;
    printf("\nP_NO\tBT\tAT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],bt[i],at[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage turn around time is %f\nAverage waiting time is %f",avg_tat,avg_wt);
    return 0;
}
void sort(int bt[],int at[],int p[],int q,int r)
{
    int i,j,temp;
    for(i=q;i<r-1;i++)
    {
        for(j=q;j<r-i;j++)
        {
            if(bt[j]>bt[j+1])
            {
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
