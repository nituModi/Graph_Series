//Kahn's Algorithm


#include<bits/stdc++.h>
using namespace std;
bool checkForCycle(int n,vector<int> adj[])
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
      int cnt=0;
      while(!q.empty())
      {
          int node=q.front();
          q.pop();
          cnt++;
          topo.push_back(node);
          for(auto it: adj[node])
          {
             inDegree[it]--;
             if(inDegree[it]==0)
             q.push(it);
          }
      }
      if(cnt==n)
        return false;
      else
        return true;
      
 }
 int main()
 {
     int nodes,edge;
     cin>>nodes>>edge;
     vector<int> adj[nodes];    // 0 based indexing
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
    if(checkForCycle(nodes,adj))
       cout<<"yes";
    else
       cout<<"no";
 }


//  input
// 4 4
// 0 1
// 1 2
// 2 3
// 3 1

//output
//yes

 