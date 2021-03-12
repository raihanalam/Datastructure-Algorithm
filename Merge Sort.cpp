#include<iostream>
using namespace std;
int i,j,k;
void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 =  r - q;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[p+i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    i = 0;
    j = 0;
    for(k=p;k<r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
int merge_sort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}
int main()
{
    int n=10,p=0;
    int A[20];
    cout<<"Enter Numbers:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    merge_sort(A,p,n);
    cout<<"Sorted List:"<<endl;
    for (i=0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }
    return 0;
}
