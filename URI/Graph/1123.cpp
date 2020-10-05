#include <bits/stdc++.h>
#define MAX 1e+07

using namespace std;

typedef pair<int, int> ii;

int dijkstra(vector<ii> graph[], int size, int source, int end) {
    priority_queue <ii> pq;
    map <int, int> dist;

    //Itializa distance
    for(int i = 0; i < size; i++) dist[i] = MAX;

    // Max heap on distance
    pq.push(ii(0, source));
    dist[source] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;

        pq.pop();

        for(auto x:graph[u]) {
            int v = x.first;
            int w = x.second;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }

    return dist[end];
}

int main() {
    int m, n, c, k, u, v, p;

    vector <ii> xs[1000];

    while(1) {
        cin >> n >> m >> c >> k;
        if(!(m || n || c || k)) break;
            while(m--) {
            cin >> u >> v >> p;

            if(v >= c && u >= c) {
                xs[u].push_back(ii(v, p));
                xs[v].push_back(ii(u, p));
            }

            if(v < c && u >=c) {
                xs[u].push_back(ii(v, p));
            } 

            if(u < c && v >= c) {
                xs[v].push_back(ii(u, p));
            } 

            if( u < c && v < c && abs(v-u) == 1) {
                xs[u].push_back(ii(v, p));
                xs[v].push_back(ii(u, p));
            }
            
        }

        cout << dijkstra(xs, n, k, c-1) << endl;

        for(auto& x:xs) x.clear();
    } 

    return 0;
}