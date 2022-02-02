#include<bits/stdc++.h>
using namespace std;
bool  checkCycleByDfs(int i,vector<int> &vis,vector<int> &dfsvis,vector<int> adj[])
{
    dfsvis[i]=1;
    vis[i]=1;
    for(auto it: adj[i])
    {
        if(!vis[it])
        {
            checkCycleByDfs(it,vis,dfsvis,adj);
        }
        else if(dfsvis[it])
           return true;
    }
    dfsvis[i]=0;
    return false;
}
bool checkForCycle(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    vector<int> dfsvis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            if(checkCycleByDfs(i,vis,dfsvis,adj))
               return true;
        }
    }
    return false;
}
int main()
{
    int nodes,edge;
    cin>>nodes>>edge;
    vector<int> adj[nodes+1];
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkForCycle(nodes,adj))
       cout<<"yes";
    else   cout<<"no";
}