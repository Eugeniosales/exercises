#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(E+V) -> E = Edges, V = Vertices
// Space Complexity O(V)

typedef vector <int> vt;

void dfsUtil(vt graph[], vector <bool> visited, int source, int destination) {
    if (source == destination) {
        cout << "Found" << endl;
    }

    visited[source] = true;

    cout << source << "  " << destination << endl;
    
    for (auto v:graph[source]) {
        if(!visited[v]) {
            dfsUtil(graph, visited, v, destination);
        }
    }
}

void dfs(vt graph[], int size, int start, int end) {
    vector <bool> visited(size, false);
    //bool visited[size];
    //memset(visited, false, size * sizeof(bool));

    visited[start] = true;

    dfsUtil(graph, visited, start, end);

}

int main() {
    vt graph[10000];

    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);

    dfs(graph, 4, 0, 3);

    return 0;
}