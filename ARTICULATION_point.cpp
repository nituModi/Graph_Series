#include<bits/stdc++.h>
using namespace std;
void dfs(int node,int parent,vector<int> &vis,vector<int> &in,vector<int> &low,int timer,vector<int> adj[],vector<int> &isArticulation)
{
    int child=0;
    vis[node]=1;
    low[node]=in[node]=timer++;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,node,vis,in,low,timer,adj,isArticulation);
            if(low[it]>=in[node]&& parent!=-1)
            {
                isArticulation[node]=1;
            }
            low[node]=min(low[it],low[node]);
            child++;
        }
        else if(it==parent)
           continue;
        else{
            low[node]=min(low[node],low[it]);
        }
    }
    if(parent==-1&&child>1)
       isArticulation[node]=1;
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
        adj[v].push_back(u);
    }
    vector<int> low(nodes,-1);
    vector<int> in(nodes,-1);
    vector<int> vis(nodes,0);
    vector<int> isArticulation(nodes,0);
    int timer=0;
  for(int i=0;i<nodes;i++)
  {
      if(!vis[i])
         dfs(i,-1,vis,in,low,timer,adj,isArticulation);
  }
  for(int i=0;i<nodes;i++)
  {
      if(isArticulation[i]==1)
         cout<<i<<endl;
  }
  return 0;
}
// input
// 5 5
// 0 1
// 0 2
// 1 2
// 1 3
// 3 4


// output
// 1
// 3