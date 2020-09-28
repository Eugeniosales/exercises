#include <bits/stdc++.h>

using namespace std;

vector <int> xs[1000010];

void bfs(vector<int>graph[], int size, int st) {
    map <int, bool> marked;
    map <int, int> level;
    queue <int> q;

    for(int i = 0; i < size; i++) marked[i+1] = false;

    int cn = 0;
    for(int k = st; k <= size; k++) {
        if(!marked[k]) {
            q.push(k);
            marked[k] = true;
            cn++;
            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto i:graph[node]) {
                    if(!marked[i]) {
                        marked[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }

    cout << cn << endl;
}

int main() {
    int n, m, a, b;

    cin >> n >> m;

    while(m--) {
        cin >> a >> b;
        xs[a].push_back(b);
    }

    bfs(xs, n, 1);

    return 0;
}