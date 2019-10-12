#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end,total;
    start=clock();
    int n;
    printf("Enter number of activities: ");
    scanf("%d",&n);
    int activity[n],strt[n],ed[n],i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the activity number: ");
        scanf("%d",&activity[i]);
        printf("Enter its start time: ");
        scanf("%d",&strt[i]);
        printf("Enter its end time: ");
        scanf("%d",&ed[i]);
    }
    mergesort(activity,strt,ed,0,n-1);
    activitysol(activity,strt,ed,n);
    end=clock();
    total=(float)((end-start)/CLOCKS_PER_SEC);
    printf("\n\nExecution time is %f",total);
    return 0;
}
void mergesort(int A[],int S[],int E[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(A,S,E,p,q);
        mergesort(A,S,E,q+1,r);
        merge(A,S,E,p,q,r);
    }
}
void merge(int A[],int S[],int E[],int p,int q,int r)
{
    int n1=q-p+1,n2=r-q,i,j,k;
    int L[n1+1],R[n2+1],L1[n1],L2[n1],R1[n2],R2[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=E[p+i];
        L1[i]=S[p+i];
        L2[i]=A[p+i];
    }
    for(i=0;i<n2;i++)
    {
        R[i]=E[q+i+1];
        R1[i]=S[q+i+1];
        R2[i]=A[q+i+1];
    }
    L[n1]=30000;
    R[n2]=30000;
    i=0;j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            E[k]=L[i];
            S[k]=L1[i];
            A[k]=L2[i];
            i++;
        }
        else
        {
            E[k]=R[j];
            S[k]=R1[j];
            A[k]=R2[j];
            j++;
        }
    }
}
void activitysol(int A[],int S[],int E[],int l)
{
    int i=0,j;
    printf("\nActivity numbers performed in sequence:\n%d",A[i]);
    for(j=1;j<l;j++)
    {
        if(E[i]<=S[j])
        {
            printf(" --> %d",A[j]);
            i=j;
        }
    }
}

