#include<bits/stdc++.h>
using namespace std;
bool bipartiteByBfs(int i,vector<int> adj[],vector<int> &clr)
{
   queue<int> q;
   q.push(i);
   clr[i]=1;
   while(!q.empty())
   {
       int node=q.front();
       q.pop();
       for(auto it: adj[node])
       {
           if(clr[it]==-1)
           {
              clr[it]=1-clr[node];
              q.push(it);
           }
           else if(clr[it]==clr[node])
             return false;
       }
   }
   return true;
}
bool checkForBipartite(int v,vector<int> adj[])
{
    vector<int> clr(v+1,-1);
   for(int i=1;i<=v;i++)
   {
       if(clr[i]==-1)
       {
           if(!bipartiteByBfs(i,adj,clr))
           {
               return false;
           }
       }
   }
   return true;
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
        for(auto it:adj[i])
        {
            cout<<it<<' ';
        }
        cout<<endl;
    }
    if(checkForBipartite(n,adj))
        cout<<"yes";
    else  
       cout<<"NO";
    return 0;
}