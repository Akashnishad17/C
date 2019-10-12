#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start,end,total;
    start=clock();
    int arr[5],i,j,temp;
    printf("Enter numbers in the array\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<5-1;i++)
    {
        for(j=0;j<5-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted elements using bubble sort are :\n");
    for(i=0;i<5;i++)
    {
        printf("%d\n",arr[i]);
    }
    end=clock();
    total=(double)((end-start)/CLOCKS_PER_SEC);
    printf("\nExecution time is %lf",total);
    return 0;
}
