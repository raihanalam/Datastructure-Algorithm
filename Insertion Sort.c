#include<stdio.h>
void inser(int arr[10]);
int main()
{
    int i,arr[20];
    printf("Enter Value:");
    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }

    inser(arr);

}
void inser(int arr[10])
{
    int temp,i,j;
    for(i=1;i<10;i++)
    {

        j=i;
        while(j>0 && arr[j]<arr[j-1])
        {
            temp=arr[i];
            arr[j+1]=arr[j];
            arr[j]=temp;
            j=j-1;
        }
    }
    for(i=0;i<10;i++)
    {
        printf("%d\n",arr[i]);
    }
}

