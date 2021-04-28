#include <bits/stdc++.h>

using namespace std;

void dfsUtil(vector <int> graph[], bool visited[], stack <int>& st, int u) {
    visited[u] = true;

    for(auto v:graph[u]) {
        if(!visited[v]) 
            dfsUtil(graph, visited, st,v);
    }

    st.push(u);
}

void dfs(vector <int> graph[], int size) {
    bool visited[size];

    memset(visited, false, size * sizeof(bool));

    stack <int> st;

    for(int i = 1; i < size; i++) {
        if(!visited[i]) {
            dfsUtil(graph, visited, st, i);
        }
    }

    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main() {
    vector <int> graph[10000];
    int v, e, n1, n2;

    while(scanf("%d %d", &v, &e)) {
        while(e--) {
            scanf("%d %d", &n1, &n2);
            graph[n1].push_back(n2);
        }

        dfs(graph, v+1);

        for(auto &x:graph) x.clear();
    }

    return 0;
}