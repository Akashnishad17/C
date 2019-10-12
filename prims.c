#include<stdio.h>
int n;
int prims(int A[][n],int r,int n);
int main()
{
    int i,j,x,mct;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    int A[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            A[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                continue;
            if(A[j][i]>0)
                continue;
            printf("Enter the edge length from %d to %d node: ",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the root node: ");
    scanf("%d",&x);
    mct=prims(A,x-1,n);
    printf("\nMinimum cost for the spanning tree of given graph is %d",mct);
    return 0;
}
int prims(int A[][n],int r,int n)
{
    int i,e=n,sum=0,min=0;
    struct val
    {
        int par;
        int key;
    };
    struct val node[n];
    for(i=0;i<n;i++)
    {
        node[i].par=-1;
        node[i].key=35000;
    }
    node[r].key=0;
    while(e>0)
    {
        for(i=0;i<n;i++)
        {
            if(A[r][i]>0)
            {
                node[i].par=r;
                node[i].key=A[r][i];
            }
            if(A[i][r]>0)
            {
                node[i].par=r;
                node[i].key=A[i][r];
            }
            printf("%d\n",node[i].key);
        }
        for(i=0;i<n-1;i++)
        {
            if(node[min].key>node[i+1].key)
                min=i+1;
        }
        printf("%d %d\n",r+1,min+1);
        sum+=node[min].key;
        e--;
        r=min;
        node[min].key=35000;
        min=0;
    }
    return sum;
}
