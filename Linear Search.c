#include<stdio.h>
int main()
{
    int x[20],i,y;
    for(i=0;i<10;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("Enter What you want to search:");
    scanf("%d",&y);
    for(i=0;i<10;i++)
    {
        if(x[i]==y)
            y=i;
    }
    printf("%d is the location",y+1);
}
