#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes,edge;
    cin>>nodes>>edge;
    vector<pair<int,int>> adj[nodes];
    for(int i=0;i<edge;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int key[nodes];
    bool mstSet[nodes];
    int parent[nodes];
    for(int i=0;i<nodes;i++)
      key[i]=INT_MAX, mstSet[i]=false,parent[i]=-1;

    key[0]=0;
  for(int count=0;count<nodes-1;count++)
  {
      int min=INT_MAX,u;
      for(int i=0;i<nodes;i++)
      {
          if(mstSet[i]==false&& key[i]<min)
             min=key[i],u=i;
      }
      mstSet[u]=true;
      for(auto it: adj[u])
      {
          int v=it.first;
          int weight=it.second;
          if(mstSet[v]==false&&weight<key[v])
             key[v]=weight, parent[v]=u;
      }
  }
   for(int i=1;i<nodes;i++)
   {
       cout << parent[i] << " - " << i <<" \n"; 
   }
   return 0;
}