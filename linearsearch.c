#include<stdio.h>
int main()
{
    int arr[5],i,n;
    printf("Enter the numbers in the array\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter a number to search : ");
    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        if(n==arr[i])
        {
            printf("Number found\n");
            break;
        }
    }
    return 0;
}
