#include <bits/stdc++.h>

using namespace std;

void bfs(vector <int> graph[], int size) {
    queue <int> q;
    map <int, bool> marked;
    vector <int> comp[1000];

    int start = (int) 'a';
    int end = 'a' + size;

    for(int i = start; i < end; i++) {
        marked[i] = false;
    }

    int p = -1;
    for(int i = start; i < end; i++) {
        if(!marked[i]) {
            ++p;

            // Vector of connected components
            comp[p].push_back(i);
            
            q.push(i);
            while(!q.empty()) {
                int v = q.front();
                marked[v] = true;
                q.pop();
                
                for(auto u:graph[v]) {
                    if(!marked[u]) {
                        marked[u] = true;
                        q.push(u);
                        comp[p].push_back(u);
                    }
                }
            }
        }
    }
    for(int i = 0; i < p+1; i++){
        sort(comp[i].begin(), comp[i].end());
        for(auto x:comp[i]) printf("%c,", x);
        printf("\n");
    }

    printf("%d connected components\n\n", p+1);
}

int main() {
    int n, v, e;
    char u, w;
    vector <int> xs[10000];

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v >> e;
        
        while(e--) {
            cin >> u >> w;

            for(int i = 'a'; i < 'a' + v; i++)
                xs[i].push_back(i);

            xs[(int) u].push_back((int) w);
            xs[(int) w].push_back((int) u);

        }

        printf("Case #%d:\n", i);
        bfs(xs, v);

        for(auto& x:xs) {
            x.clear();
        }
    }

    return 0;
}