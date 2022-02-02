#include<bits/stdc++.h>
using namespace std;
void dfsOfGraph(int i,vector<int> &vis,vector<int> adj[],vector<int> &dfs)
{
     dfs.push_back(i);
     vis[i]=1;
     for(auto it: adj[i])
     {
         if(!vis[it])
         {  
            dfsOfGraph(it,vis,adj,dfs);
         }
     }
}
vector<int> dfsSearch(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    vector<int> dfs;
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            dfsOfGraph(i,vis,adj,dfs);
        }
    }
    return dfs;
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
     for(int i=1;i<=n;i++)
    {
        cout<<"element at index"<<i<<":";
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    vector<int> res=dfsSearch(n,adj);
   for(int i=0;i<res.size();i++)
   {
       cout<<res[i]<<' ';
   }
   return 0;
}

// INPUT
    // 7 6
    // 1 2
    // 2 4
    // 2 7
    // 4 6
    // 7 6
    // 3 5
// OUTPUT    
   // 1 2 4 6 7 3 5
