 #include<bits/stdc++.h>
using namespace std;
int i,j,m,n,c[20][20];
char b[20][20];
char x[20],y[20];
int LCS(char x[],char y[]);
int LCS_Print(int i,int j);
int main()
{
    cout<<"Enter 1st String: ";
    gets(x);
    cout<<"Enter 2nd String: ";
    gets(y);
    LCS(x,y);
    cout<<"Longest Common Subsequence is: ";
    LCS_Print(m,n);
}
int LCS(char x[],char y[])
{
    m=strlen(x);
    n=strlen(y);
    for(i=0;i<=m;i++)
    {
        c[i][0]=0;
    }
    for(j=1;j<=n;j++)
    {
        c[0][j]=0;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='D';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='L';
            }
        }
    }
    /*for(i=0;i<=m;i++)
    {
        cout<<endl;
        for(j=0;j<=n;j++)
        {
            cout<<c[i][j]<<"\t";
        }
    }*/
}
int LCS_Print(int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(b[i][j] == 'D')
    {
        LCS_Print(i-1,j-1);
        //cout<<x[i-1];
        cout<<i<<j<<endl;
    }
    else if(b[i][j] == 'U')
    {
        LCS_Print(i-1,j);
    }
    else
    {
        LCS_Print(i,j-1);
    }
}

