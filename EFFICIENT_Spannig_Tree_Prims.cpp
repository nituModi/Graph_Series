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
    {
        key[i]=INT_MAX,mstSet[i]=false;    
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    key[0]=0;
    parent[0]=-1;
    pq.push({-1,0});  //   (distance,index)
   for(int count=0;count<nodes-1;count++)
   {
       int u=pq.top().second;
       pq.pop();
       mstSet[u]=true;
       for(auto it: adj[u])
       {
           int v=it.first;
           int weight=it.second;
           if(mstSet[v]==false && weight<key[v])
               parent[v]=u;
               key[v]=weight;
               pq.push({key[v],v});
       }
   }
   for(int i=1;i<nodes;i++)
   {
       cout << parent[i] << " - " << i <<" \n"; 
   }
   return 0;
}

// input
// 5 6
// 0 1 2
// 0 3 1
// 1 2 4
// 3 2 3
// 1 4 5
// 2 4 1


//output
