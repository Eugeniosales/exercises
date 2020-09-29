#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int>graph[], int size, int st) {
    map <int, bool> marked;
    map <int, int> level;
    queue <int> q;

    for(int i = 0; i < size; i++) marked[i+1] = false;

    q.push(st);
    marked[st] = true;
    level[st] = 0;

    
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto i:graph[node]) {
            if(!marked[i]) {
                marked[i] = true;
                q.push(i);
                level[i] = level[node] + 1;
            }
        }
    }

    int max = -1;
    bool cn = true;
    for(auto x:level) {
        max = max < x.second? x.second : max;
    }
    for(auto x:marked) if(!x.second) cn = false;

    cout << (max <= 6 && cn? "S":"N" ) << endl;
}

int main() {
    int n, m, a, b;
    vector <int> xs[1000];

    cin >> n >> m;

    while(m--) {
        cin >> a >> b;
        xs[a].push_back(b);
        xs[b].push_back(a);
    }

    bfs(xs, n, 1);

    return 0;
}