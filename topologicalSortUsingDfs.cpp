#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int> adj[],vector<int> &vis,stack<int> &stk)
{
    vis[i]=1;
    for(auto it: adj[i])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,stk);
        }
    }
  stk.push(i);
}
 vector<int> topologicalSort(int v,vector<int> adj[])
 {
    stack<int> stk;
    vector<int> vis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,stk);
        }
    }
    vector<int> topo;
    while(!stk.empty())
    {
        topo.push_back(stk.top());
        stk.pop();
    }
    return topo;
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
        // adj[v].push_back(v);
    }
    vector<int> ans=topologicalSort(nodes,adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
// input
// 6 6
// 6 1
// 5 1
// 5 2
// 4 1
// 2 3
// 3 1

//output
//6 5 4 2 3 1 