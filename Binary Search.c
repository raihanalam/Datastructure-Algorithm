#include<stdio.h>
int main()
{
    int i,x[20],n=10,search,mid,first=0,last=n-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }

    printf("Search:");
    scanf("%d",&search);
    mid=(first+last)/2;

    while(first<=last)
    {
        if(x[mid]<search)
            first=mid+1;
        else if(x[mid]==search)
        {
            printf("%d is location",mid+1);
            break;
        }
        else
            last=mid-1;
        mid=(first+last)/2;

    }
    if(first>last)
        printf("Not Found");
}
