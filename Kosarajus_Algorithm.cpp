//strongly connected component in directed Graph
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> &vis,stack<int> &stk,vector<int> adj[])
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,stk,adj);
        }
    }
    stk.push(node);
}
void revDfs(int node,vector<int> &vis,vector<int> transpose[])
{
    cout<<node<<" ";
    vis[node]=1;
    for(auto it:transpose[node])
    {
        if(!vis[it])
        {
            revDfs(it,vis,transpose);
        }
    }
}
int main()
{
    int nodes,edge;
    cin>>nodes>>edge;
    vector<int> adj[nodes];
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<int> stk;
    vector<int> vis(nodes,0);
    for(int i=0;i<nodes;i++)
    {
        if(!vis[i])
          dfs(i,vis,stk,adj);
    }
    vector<int> transpose[nodes];
    for(int i=0;i<nodes;i++)
    {
        vis[i]=0;
        for(auto it: adj[i])
            transpose[it].push_back(i);
    }
    while(!stk.empty())
    {
        int node=stk.top();
        stk.pop();
        if(!vis[node])
        {
           cout<<"SCC:";
           revDfs(node,vis,transpose);
           cout<<endl;
        }
    }
 return 0;
}