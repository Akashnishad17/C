#include<stdio.h>
#include<time.h>
main()
{
    clock_t start,end,total;
    start=clock();
    int i;
    for(i=1;i<100;i++){}
    end=clock();
    total=(float)((end-start)/CLOCKS_PER_SEC);
    printf("Execution time is %f",total);
    return 0;
}
