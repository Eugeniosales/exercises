#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> g;

int dijkstra(g graph[], int source, int end, int size, int agree[][MAX]) {
    priority_queue <ii, vector<ii>, greater<ii>> pq;
    map <int, int> dist;

    for(int i = 0; i < size; i++) dist[i] = MAX;

    dist[source] = 0;

    pq.push(ii(0, source));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto x:graph[u]) {
            int v = x.first;

            int w = agree[u][v] + agree[v][u] == 2? 0:x.second;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }
    return dist[end];
}

int main() {
    int n = 1, e = 1, x, y, h, k, o, d;
    g xs[MAX];
    int mp[MAX][MAX];

    while(1) {
        cin >> n >> e;
        if(!(n || e)) break;

        memset(mp, 0, sizeof(mp));

        while(e--) {
            cin >> x >> y >> h;
            x = x -1;
            y = y -1;
            xs[x].push_back(ii(y, h));
            mp[x][y] = 1;
        }

        cin >> k;

        while(k--) {
            cin >> o >> d;
            int res = dijkstra(xs, o-1, d-1, n, mp);
            if(res != MAX) cout << res << endl;
            else cout << "Nao e possivel entregar a carta" << endl;
        }
        cout << endl;

        for(auto& x:xs) x.clear();
    }

    return 0;
}