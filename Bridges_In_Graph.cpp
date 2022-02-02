#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &in, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node]=1;
    in[node]=low[node]=timer++;
    for(auto it : adj[node]){
        //if the adjacent element is parent, we'll not do a dfs call because we know
        // that it will go backward
        if(it == parent) continue;
        
        if(!vis[it]){
            /* call dfs for adjacent nodes, now when dfs will be called, time of insertion 
            will increase and low of node will increase */
            dfs(it, node, vis, in, low, timer, adj);     //forward edge
            //low of the node will be updated whose dfs is completed
            //it will be updated only if the adjacent node have lesser low
            low[node] = min(low[node], low[it]);
            
            //if this condition follows that does mean that the node is visited by some other 
            //component and not this component, therefore it is a bridge
            if(low[it]>in[node]){
                cout<<node<<"-"<<it<<endl;
            }
         }
         //else if the node is already visited, then just update the low of the node
         /*this does mean if the node is previously visited, then there is possibility that
         the time of insertion would be lowest for that , so update it */
         else{
            low[node] = min(low[node], in[it]);     //back edge
         }
    }

}
int main()
{
    int nodes,edge;
    cin>>nodes>>edge;
    vector<int> adj[nodes+1];
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> tin(nodes+1,-1);  // time of insertion
    vector<int> low(nodes+1,-1);   //low time insertion
    vector<int> vis(nodes+1,0);
    int timer=0;
    for(int i=1;i<=nodes;i++)
    {
        if(!vis[i])
            dfs(i,-1,vis,tin,low,timer,adj);
    }
    return 0;
}

//  input
// 4 4
// 0 1
// 1 2
// 2 3
// 1 3


// input
// 12 14
// 1 2
// 1 4
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7
// 7 8
// 8 9
// 6 9
// 8 10
// 10 11
// 11 12
// 10 12



// output
// 0-1