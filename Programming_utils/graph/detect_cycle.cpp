#include <bits/stdc++.h>

using namespace std;

enum color { WHITE, GRAY, BLACK };

int isCycle;

bool dfsUtil(vector <int> graph[], int visited[], int u) {
    visited[u] = GRAY;

    for(auto v:graph[u]) {
        if(visited[v] == GRAY) {
            return true;
        }
        if(visited[v] == WHITE && dfsUtil(graph, visited, v)) {
            return true;
        }
    }

    visited[u] = BLACK;
    return false;
}

bool dfs(vector <int> graph[], int size) {
    int visited[size];
    memset(visited, WHITE, size * sizeof(int));

    for(int i = 1; i < size; i++) {
        if(visited[i] == WHITE)
            if(dfsUtil(graph, visited, i)) return true;
    }

    return false;
}

int main() {
    int n, m, u, v;
    vector <int> graph[100000];

    cin >> n >> m;
    isCycle = false;
    while(m--) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    cout << (dfs(graph, n+1)?"Bolada": "Nao Bolada") << endl;

    return 0;
}