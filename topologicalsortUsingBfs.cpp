//Kahn's Algorithm


#include<bits/stdc++.h>
using namespace std;
 vector<int> topoSort(int n,vector<int> adj[])
 {
      vector<int> inDegree(n,0);
      for(int i=0;i<n;i++)
      {
         for(auto it: adj[i])
         {
            inDegree[it]++;
         }
      }
      queue<int> q;
      for(int i=0;i<n;i++)
      {
          if(inDegree[i]==0)
             q.push(i);
      }
      vector<int> topo;
      while(!q.empty())
      {
          int node=q.front();
          q.pop();
          topo.push_back(node);
          for(auto it: adj[node])
          {
             inDegree[it]--;
             if(inDegree[it]==0)
             q.push(it);
          }
      }
      return topo;
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
        vector<int> ans=topoSort(nodes,adj);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }

    return 0;
}


// input
// 6 6
// 5 2
// 2 3
// 3 1
// 4 1
// 4 0
// 5 0




//output

//4 5 2 0 3 1