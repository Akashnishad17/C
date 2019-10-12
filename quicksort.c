#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end,total;
    start=clock();
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,n-1);
    printf("Sorted elements are\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    total=(float)((end-start)/CLOCKS_PER_SEC);
    printf("\nExecution time is %f",total);
    return 0;
}
void quicksort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}
int partition(int A[],int p,int r)
{
    int x=A[r],i=p-1,j,temp;
    for(j=p;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}

