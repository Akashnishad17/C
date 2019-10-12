#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{
    char text[20],pattern[20],a,b;
    printf("Enter a text : ");
    scanf("%s",&text);
    printf("Enter a pattern : ");
    scanf("%s",&pattern);
    int i=0,count=0,j;
    a=pattern[i];
    for(j=0;j<strlen(text);j++)
    {
        b=text[j];
        if(a==b)
        {
            i++;
            if(i==strlen(pattern))
            {
                count++;
                i=0;
            }
            a=pattern[i];
        }
    }
    if(count>0)
            printf("Match found %d time(s)\n",count);
        else
            printf("Not found\n");
    return 0;
}
