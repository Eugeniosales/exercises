#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<int> xs[], int size, int st) {
    map <int, bool> marked;
    queue <int> q;

    for(int i = 0; i < size; i++) marked[i+1] = false;

    q.push(st);
    marked[st] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto i:xs[node]) {
            if(!marked[i]) {
                marked[i] = true;
                q.push(i);
            }
        }
    }

    bool ans = true;

    for(auto x:marked) if(!x.second) ans = false;

    return ans;

}

int main() {

    int n = 1, m = 1, v, w, p;
    vector <int> gs [10000], gr[10000]; 


    while(1) {
        cin >> n >> m;

        if(!n && !m) return 0;

        for(int i = 0; i < m; i++) {
            cin >> v >> w >> p;

            gs[v].push_back(w);
            gr[w].push_back(v);

            if(p == 2) {
                gs[w].push_back(v);
                gr[v].push_back(w);
            }
        }

        cout << ( bfs(gs, n, 1) && bfs(gr, n, 1) ? 1 : 0 ) << endl;

        
        for (auto& v : gs) {
            v.clear();
        }

        for (auto& v : gr) {
            v.clear();
        }
    }

    return 0;
}