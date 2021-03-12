#include<iostream>
using namespace std;
int adj[20][20],visited[20]={0};
int n;
void DFS(int S)
{
    int j;
    cout<<S<<endl;
    visited[S]=1;
    for(j=0;j<n;j++)
    {
        if(adj[S][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
}
int main()
{
    int i,j,s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    cin>>s;
    DFS(s);
}
