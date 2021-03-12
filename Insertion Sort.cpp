#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int *insertion(int arr[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
          arr[j+1]=arr[j];
          arr[j]=temp;
          --j;
        }
    }
    return arr;
}
int main()
{
    int *x,arr[20],n=10,i;
    cout<<"Enter numbers: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    x=insertion(arr,n);
    cout<<"Sorted List";
    for(i=0;i<n;i++)
    {
        cout<<*x<<endl;
        *x++;
    }
}

