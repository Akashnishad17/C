#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end,total;
    start=clock();
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    int i,M;
    float p[n],w[n],ratio[n],profit=0,x=1;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the profit for item %d: ",i+1);
        scanf("%f",&p[i]);
        printf("Enter the weight for item %d: ",i+1);
        scanf("%f",&w[i]);
        ratio[i]=p[i]/w[i];
    }
    mergesort(p,w,ratio,0,n);
    printf("\nEnter the weight of knapsack: ");
    scanf("%d",&M);
    for(i=0;i<n;i++)
    {
        if(M>0)
        {
            if(M-w[i]<0)
            {
                x=M/w[i];
            }
            profit+=x*p[i];
            M=M-w[i];
        }
    }
    printf("\nMaximum Profit is %f\n",profit);
    end=clock();
    total=(float)((end-start)/CLOCKS_PER_SEC);
    printf("Execution time is %f",total);
    return 0;
}
void mergesort(float A[],float S[],float E[],int p,int r)
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
void merge(float A[],float S[],float E[],int p,int q,int r)
{
    int n1=q-p+1,n2=r-q,i,j,k;
    float L[n1+1],R[n2+1],L1[n1],R1[n2],L2[n1],R2[n2];
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
    L[n1]=0;
    R[n2]=0;
    i=0;j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]>=R[j])
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
