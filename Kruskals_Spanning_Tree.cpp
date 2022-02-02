#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,wt;
    node(int first,int second,int third)
    {
       u=first;
       v=second;
       wt=third;
    }
};
bool comp(node a,node b)
  {
      return a.wt<b.wt;
  }
int findPar(int u,vector<int> &parent)
  {
      if(u==parent[u])
         return u;
      return parent[u]=findPar(parent[u],parent);  //  do compression
  }
void dounion(int u,int v,vector<int>&parent,vector<int> &rank)
  {
      u=findPar(u,parent);
      v=findPar(v,parent);
      if(rank[u]<rank[v])
         parent[u]=v;
      else if(rank[v]<rank[u])
          parent[v]=u;
      else
          {
              parent[v]=u;
              rank[u]++;
          }  
  }
int main()
{
    int n,edge;
    cin>>n>>edge;
    vector<node> ans;
    for(int i=0;i<edge;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        ans.push_back(node(u,v,wt));
    }
    sort(ans.begin(),ans.end(),comp);
    vector<int> parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    vector<int> rank(n,0);
    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it: ans)
    {
        if(findPar(it.v,parent)!=findPar(it.u,parent))
        {
            cost+=it.wt;
            mst.push_back({it.u,it.v});
            dounion(it.u,it.v,parent,rank);
        }
    }
    for(auto it: mst)
    {
        cout<<it.first<<"-"<<it.second<<endl;
    }
    return 0;
}