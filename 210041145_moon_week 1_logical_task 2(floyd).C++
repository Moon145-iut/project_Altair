    #include<iostream>
    #include "bits/stdc++.h"
    using namespace std;
    const int INF = 1e9;
    int main()
    {vector<vector<int>>graph = { {0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}
    };

    int i,j,k, num_vertex = graph.size();
    vector<vector<int>>dist = graph;
    for(i=0;i<num_vertex;i++)
    {
         for(j=0;j<num_vertex;j++)
         {
             for(k=0;k<num_vertex;k++)
             {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];// relax
                }
             }
         }}
          for(j=0;j<num_vertex;j++)
         {
             for(k=0;k<num_vertex;k++)
             {
                if(dist[i][j] = INF)
                {
                    cout<<"INF ";
                }
                else
                {
                    cout<<dist[i][j]<<" ";
                }}}


    }
