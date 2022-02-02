 #include<bits/stdc++.h>
 using namespace std;
 bool  check_for_cycle(int i,int v,vector<int> adj[],vector<int> &vis)
 {
    stack<pair<int,int>> q;
    vis[i]=1;
    q.push({i,-1});
    while(!q.empty())
    {
        int node=q.top().first;
        int pre=q.top().second;
        q.pop();

        for(auto it:adj[i])
          {
              if(!vis[it])
              {
                  vis[it]=1;
                  q.push({it,node});
              }
              else if(pre!=it)
                return true;
          }
    }
    return false;
 }
 bool isCycle(int v,vector<int> adj[])
 {
     vector<int> vis(v+1,0);                                                          
     for(int i=1;i<=v;i++)
     {
         if(!vis[i])
         if(check_for_cycle(i,v,adj,vis))
            return true;
     }
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
            cout<<*it<<' ';
        }
        cout<<endl;
    }
    cout<<isCycle(n,adj);
    return 0;
}