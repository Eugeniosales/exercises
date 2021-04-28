#include <bits/stdc++.h>

using namespace std;

// make dikstra
// print parents

typedef pair <int, int> ii;

void find_parents(map <int, int> parent, int node) {
    while(parent[node] != -1) {
        cout << parent[node] << "  ";
        node = parent[node];
    }
    cout << endl;
}

int dijkstra(vector <ii> graph[], int size, int start, int end) {
    priority_queue <ii> pq;
    vector <int> dist(size, INT_MAX);
    map <int, int> parents;


    dist[start] = 0;
    parents[0] = -1;
    pq.push({ 0, start });

    while(!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        for(auto x:graph[u]) {
            int w = x.second;
            int v = x.first;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v ));
                parents[v] = u;
            }
        }
    }

    find_parents(parents, 3);

    return dist[end];
}

int main() {
    vector <ii> graph[1000];

    graph[0].push_back({1, 4 });
    graph[0].push_back(ii( 7, 8 ));
    graph[1].push_back(ii(2, 8 ));
    graph[1].push_back(ii(7, 11 ));
    graph[2].push_back(ii(3, 7 ));
    graph[2].push_back(ii(8, 2 ));
    graph[2].push_back(ii(5, 4 ));
    graph[3].push_back(ii(4, 9 ));
    graph[3].push_back(ii(5, 14 ));
    graph[4].push_back(ii(5, 10 ));
    graph[5].push_back(ii(6, 2 ));
    graph[6].push_back(ii(7, 1 ));
    graph[6].push_back(ii(8, 6 ));
    graph[7].push_back(ii(8, 7 ));

    cout << dijkstra(graph, 9, 0, 8) << endl;
    return 0;
}