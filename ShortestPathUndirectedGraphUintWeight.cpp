#include<bits/stdc++.h>
using namespace std;
void shortestPath(int n,vector<int> adj[],int src)
 {
     int dis[n];
     for(int i=0;i<n;i++)
     {
         dis[i]=INT_MAX;
     }
     queue<int> q;
     dis[src]=0;
     q.push(src);
     while(!q.empty())
     {
         int node=q.front();
         q.pop();
         for(auto it: adj[node])
         {
             if(dis[node]+1<dis[it])
             {
                 dis[it]=dis[node]+1;
                 q.push(it);
             }
         }
     }
     for(int i=0;i<n;i++)
     {
        cout<<dis[i]<<" ";
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
        adj[v].push_back(u);
    }
     for(int i=0;i<nodes;i++)
    {
         cout<<"element at index"<<i<<":";
        for(auto it:adj[i])
        {
            cout<<it<<' ';
        }
        cout<<endl;
    }
    shortestPath(nodes,adj,0);
    return 0;
}

// input
// 9 11
// 0 1
// 0 3
// 1 3
// 3 4
// 4 5
// 5 6
// 1 2
// 2 6
// 6 7
// 6 8
// 7 8



// output
// 0 1 2 1 2 3 3 4 4 