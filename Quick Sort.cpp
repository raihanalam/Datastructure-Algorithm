#include<iostream>
using namespace std;
int QuickSort(int arr[],int p,int r);
int Partition(int arr[],int p,int r);
int main()
{
    int arr[50],p=0,r=10;
    cout<<"Enter Numbers:"<<endl;
    for(int i=0;i<r;i++)
    {
        cin>>arr[i];
    }
    QuickSort(arr,p,r);
    cout<<"Sorted List:"<<endl;
    for(int i=0;i<r;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int QuickSort(int arr[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}
int Partition(int arr[],int p,int r)
{
    int x,i,j,temp;
    x=arr[r];
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(arr[j]<=x)
        {
            i=i+1;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return i+1;
}
