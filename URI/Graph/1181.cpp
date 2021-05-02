#include <bits/stdc++.h>

using namespace std;

// DFS O(V+E)
// Add counter
// Print

typedef unordered_map <int, int> ump;

void dfsUtil(vector <int> graph[], bool visited[], ump hist, int parent, int u) {
    visited[u] = true;

    hist[u] = hist[parent] + 2;

    for(auto v:graph[u]) {
        if(!visited[v]) {            
            for(int i = 0; i < hist[u]; i++)
                cout << " ";
            printf("%d-%d pathR(G,%d)\n", u, v, v);
            dfsUtil(graph, visited, hist, u, v);
        } else {
            visited[u] = true;
            for(int i = 0; i < hist[u]; i++)
                cout << " ";
            printf("%d-%d\n", u, v);
        }
    }
}

void dfs(vector <int> graph[], int size, unordered_set <int> st) {
    bool visited[size];
    memset(visited, false, sizeof(visited));

    ump hist;
    for(int i = 0; i < size; i++) {
        if(!visited[i]) {
            dfsUtil(graph, visited, hist, -1, i);
            if(st.find(i) != st.end() && i != size - 1)
                cout << endl;
        }
    }
    
    hist.clear();
}


int main() {
    int n, v, e, u, a;
    vector <int> graph[30];
    unordered_set <int> st;

    int k = 1;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> v >> e;
            while(e--) {
                cin >> u >> a;
                graph[u].push_back(a);
                st.insert(u);
                st.insert(a);
            }

            for(int i = 0; i < v; i++)
                sort(graph[i].begin(), graph[i].end());

            printf("Caso %d:\n", k);
            dfs(graph, v, st);
            k++;
            for(auto& x:graph) x.clear();
        }
    }
    return 0;
}