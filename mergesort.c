#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end,total;
    start=clock();
    int arr[10],i;
    printf("Enter the elements:\n");
    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);
    mergesort(arr,0,10-1);
    printf("Sorted elements are\n");
    for(i=0;i<10;i++)
        printf("%d\t",arr[i]);
    total=(float)((end-start)/CLOCKS_PER_SEC);
    printf("\nExecution time is %f",total);
    return 0;
}
void mergesort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        merge(A,p,q,r);
    }
}
void merge(int A[],int p,int q,int r)
{
    int n1=q-p+1,n2=r-q,i,j,k;
    int L[n1+1],R[n2+1];
    for(i=0;i<n1;i++)
        L[i]=A[p+i];
    for(i=0;i<n2;i++)
        R[i]=A[q+i+1];
    L[n1]=30000;
    R[n2]=30000;
    i=0;j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
}
