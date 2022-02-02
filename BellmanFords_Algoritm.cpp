#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int nodes,edge;
    cin>>nodes>>edge;
    vector<node> adj;
    for(int i=0;i<edge;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj.push_back(node(u,v,wt));
    }
    int src;
    cin>>src;
    int inf = 10000000; 
    vector<int> dist(nodes, inf); 
    dist[src]=0;
    for(int i = 1;i<=nodes-1;i++) {
        for(auto it: adj) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }
    int fl = 0; 
    for(auto it: adj) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i = 0;i<nodes;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }
    return 0;

}