#include<stdio.h>
int main()
{
    int ball[81],i,j;
    for(i=0;i<81;i++)
    {
        ball[i]=5;
    }
    printf("Enter the index: ");
    scanf("%d",&j);
    ball[j]=2;
    lightball(ball,0,81);
    for(i=0;i<81;i++)
    {
        printf("%d\n",ball[i]);
    }
    return 0;
}
void lightball(int A[],int i,int j)
{
    if(j-i<=3)
        search(A,i,j);
    if(j-i>3)
    {
        lightball(A,i,j/2);
        lightball(A,j/2+1,j);
    }
}
void search(int A[],int i,int j)
{
    printf("Hello %d %d\n",i,j);
    if(j-i==2)
    {
        if(A[i]<A[i+1])
            printf("%d %d",A[i],i);
        if(A[i+1]<A[i])
            printf("%d %d",A[i+1],i+1);
        if(A[i+1]<A[i+2])
            printf("%d %d",A[i+1],i+1);
        if(A[i+2]<A[i+1])
            printf("%d %d",A[i+2],i+2);
    }
    if(j-i==1)
    {
        if(A[i]<A[i+1])
            printf("%d %d",A[i],i);
        if(A[i+1]<A[i])
            printf("%d %d",A[i+1],i+1);
    }
}
