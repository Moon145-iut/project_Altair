#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int inf = 1e9;

int main() {
    int i, vertex, edges;
    int x, y, z;
    cin >> vertex >> edges;

    vector<int> dist(vertex + 1, inf);
    vector<vector<pair<int, int>>> graph(vertex + 1);

    for (i = 0; i < edges; i++) { 
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z}); // For directed graph, comment out this line
    }

    int source;
    cin >> source;
    dist[source] = 0;

    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty()) {
        auto m = *(s.begin());
        s.erase(s.begin()); 
        int x = m.second;

        for (auto it : graph[x]) {
            if (dist[it.first] > dist[x] + it.second) { 
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for (i = 1; i < vertex + 1; i++) { 
        if (dist[i] < inf) {
            cout << dist[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }

    return 0; 
}
