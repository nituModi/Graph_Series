#include<bits/stdc++.h>
using namespace std;
vector<int> bfsSearch(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    vector<int> bfs;
    queue<int> q;
    for(int i=1;i<=v;i++)
    {
       if(!vis[i])
       {
         vis[i]=1;
         q.push(i);
         while(!q.empty())
         {
           int node=q.front();
           q.pop();
           bfs.push_back(node);
           for(auto it:adj[node])
           {
             if(!vis[it]) 
             {
               q.push(it);
               vis[it]=1;
             }
           }
         }
       }
    }
    return bfs;
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> adj[n+1];
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> v=bfsSearch(n,adj);
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i]<<' ';
  }
  return 0;
}