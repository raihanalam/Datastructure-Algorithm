#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Matrix_Chain_Order(int n,int p[]);
void Print_Optimal(int i,int j);
int p[100];
int m[20][20],s[20][20];
int i,j,l,k,q;
int main()
{
    int n;
    cout<<"Enter Total Dimension Number:";
    cin>>n;
    int p[100];
    cout<<"Enter Values of All Diemension:"<<endl;
    for(int i=0;i<n+1;i++)
    {
        cin>>p[i];
    }
    cout<<"Maximum Cost: "<<Matrix_Chain_Order(n+1,p)<<endl;
    cout<<"Optimal Solution: ";
    Print_Optimal(1,n);
}
int Matrix_Chain_Order(int n,int p[])
{
    for(i=1;i<n;i++)
    {
        m[i][i]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return m[1][n-1];
}
void Print_Optimal(int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        Print_Optimal(i,s[i][j]);
        Print_Optimal(s[i][j]+1,j);
        cout<<")";
    }
}
