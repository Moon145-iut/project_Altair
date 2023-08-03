    #include<iostream>
    #include "bits/stdc++.h"
    using namespace std;
    const int INF = 1e9;
    int main(){
    int vertex, edge,i,j;
    int x,y,z;
    cin>>vertex>>edge;
    vector<vector<int>> num_edge;
    for(i=0;i<edge;i++)
    {
        cin>>x>>y>>z;
         num_edge.push_back({x,y,z});

    }
    int source;
    cin>>source;
    vector<int> dist(vertex,INF);
    dist[source] = 0;
    for(j=0;j<vertex-1;j++)
    {
        for(auto ed  : num_edge)
        {
            int x = ed[0];
            int y = ed[1];
            int z = ed[2];
            dist[y] = min(dist[y],z + dist[x]);
        }
         
    }
    for(auto in : dist)
    cout<<i;
    

    
    }

