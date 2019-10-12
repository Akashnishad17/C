#include<stdio.h>
#define MAX 10
int A[MAX],N;
int main()
{
    int med,i;
    for(i=0;i<MAX;i++)
        scanf("%d",&A[i]);
    med=selection_algorithm(0,9,5);
    printf("%d",med);
    return 0;
}

int partitions(int low,int high)
{
    int p=low,r=high,x=A[r],i=p-1,j;
    for(j=p;j<=r-1;j++)
    {
        if (A[j]<=x)
        {

            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
int selection_algorithm(int left,int right,int kth)
{
    //for(;;)
    while(1)
    {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        int len=pivotIndex-left+1;

        if(kth==len)
            return A[pivotIndex];

        else if(kth<len)
            right=pivotIndex-1;

        else
        {
            kth=kth-len;
            left=pivotIndex+1;
        }
    }
}
void swap(int a,int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
