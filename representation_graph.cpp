#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;  //  n is the number of nodes and m is the number of edges
    // int adj[n+1][m+1];  // adjacency matrix
    // for(int i=0;i<m;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }


    // using adjacency list
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
  
    // if the graph is weighted graph
    // vector<pair<int,int>> adj[n+1];
    // int w;
    // cin>>w;
    // for(int i=0;i<m;i++)
    // {
    //     int u,v;
    //     cin>>u,v;
    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    // }
    // print adjacency list
    for(int i=1;i<=n;i++)
    {
        cout<<"element at index"<<i<<":";
         for(auto it=adj[i].begin();it!=adj[i].end();it++)
         {
            cout<<*it<<' ';
         }
         cout<<endl;
    }
    return 0;
}