#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(E+V) -> E = Edges, V = Vertices
// Space Complexity O(V)

int bfs(vector <int> graph[], int size, int start, int end) {
    bool visited[size];
    map <int, int> level;
    queue <int> queue;

    memset(visited, false, sizeof(bool) * size);

    visited[start] = true;
    level[start] = 0;
    queue.push(start);

     while(!queue.empty()) {
        int node = queue.front();
        queue.pop();

        if(node == end) {
            return level[end];
        }

        for (auto adj:graph[node]) {
            if(!visited[adj]) {
                queue.push(adj);
                level[adj] = level[node] + 1;
                visited[adj] = true;
                cout << node << "  " << adj << endl;
            }
        }
    }

    return -1;
}

int main() {
    vector <int> graph[1000];
    map <string, int> airport;

    airport["LFA"] = 0;
    airport["ABC"] = 1;
    airport["EUG"] = 2;
    airport["BRU"] = 3;

    graph[airport["LFA"]].push_back(airport["ABC"]);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);

    cout << "Steps: " <<  bfs(graph, 1, 0, 3) << endl;

    return 0;
}