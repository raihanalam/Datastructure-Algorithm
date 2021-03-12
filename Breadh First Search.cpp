#include<iostream>
using namespace std;
int adj[20][20],queue[20]={0},visited[20]={0};
int i,j,n,s,front=0,rear=-1;
void Enqueue(int S)
{
    rear++;
    queue[rear]=S;
}
int Dequeue()
{
    front++;
    return queue[front-1];
}
void BFS(int S)
{
    Enqueue(S);
    while(front<=rear)
    {
        int u=Dequeue();
        for(j=0;j<n;j++)
        {
            if(adj[u][j]==1 && !visited[j])
            {
                Enqueue(j);
            }
        }
        visited[u]=1;
    }
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    cin>>s;
    BFS(s);
    for(i=0;i<n;i++)
    {
        if(visited[i]==1)
        {
            cout<<i;
        }
    }
}
