#include<stdio.h>
#include<time.h>
int binary(int a[],int,int,int);
int main()
{
    clock_t start,end,total;
    start=clock();
    int arr[10],i,j,val,temp,n;
    printf("Enter numbers in the array\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d",&n);
    for(i=0;i<10-1;i++)
    {
        for(j=0;j<10-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    val=binary(arr,0,10-1,n);
    if(val==-1)
        printf("Match not found\n");
    else
        printf("Match found at %d th location of ascending order of array\n",val+1);
    total=(float)((end-start)/CLOCKS_PER_SEC);
    printf("Execution time is %f",total);
    return 0;
}
int binary(int A[],int i,int j,int x)
{
    if(i==j)
    {
        if(A[i]==x)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid=(i+j)/2;
        if(A[mid]==x)
        {
            return mid;
        }
        else
        {
            if(A[mid]>x)
                binary(A,i,mid-1,x);
            else
                binary(A,mid+1,j,x);
        }
    }
}
