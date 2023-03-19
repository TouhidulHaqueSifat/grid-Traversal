#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj_list[N];
int visited[N];
int level[N];
void bfs(int node)
{
    queue<int>q;
    visited[node]=1;
    level[node]=0;
    //cout<<node<<" ";
    q.push(node);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        cout<<head<<" ";
        for(auto adj_node:adj_list[head])
        {
            if(visited[adj_node]==0)
            {
                visited[adj_node]=1;
                level[adj_node]=level[head]+1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int source;
    cin>>source;
    bfs(source);
    cout<<"\n";
    for(int i=0;i<nodes;i++)
    {
        cout<<i<<"->"<<level[i]<<"\n";
    }
    return 0;
}
