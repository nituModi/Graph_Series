#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes,edge,src;
    cin>>nodes>>edge;
    vector<pair<int,int>> adj[nodes+1];
    for(int i=0;i<edge;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    cin>>src;
    // Dijkstra's algorithm begins from here
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > pq;
    vector<int>dis(nodes+1,1e9);
    dis[src]=0;
     pq.push({0,src});    //({dis,from})
     while(!pq.empty())
     {
         int node=pq.top().first;
         int prev=pq.top().second;
         pq.pop();
         for(auto it: adj[prev])
         {
             if(dis[it.first]>dis[prev]+it.second)
             {
                dis[it.first]=dis[prev]+it.second;
                pq.push({dis[it.first],it.first});
             }
         }
     }
     for(int i=1;i<=nodes;i++)
     {
         cout<<dis[i]<<" ";
     }
     return 0;
}

// input
// 1 2 2
// 1 4 1
// 2 3 4
// 4 3 3
// 2 5 5
// 3 5 1


// output

