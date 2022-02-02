#include<bits/stdc++.h>
using namespace std;
vector<int> dfsSearch(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    vector<int> bfs;
    stack<int> stk;
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            stk.push(i);
            while(!stk.empty())
            {
                int node=stk.top();
                stk.pop();
                bfs.push_back(node);
                for(auto it: adj[node])
                {
                   if(!vis[it])
                   {
                       stk.push(it);
                       vis[it]=1;
                   }
                }
            }
        }
    }
    return bfs;
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
    vector<int> v=dfsSearch(n,adj);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<' ';
    }
    return 0;
}