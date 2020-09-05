// Graph - level 3

#include <bits/stdc++.h>

using namespace std;

void bfs(vector <int> graph[], int size, int start ) {

    vector <bool> marked(size, false);
    queue <int> q;

    q.push(start);
    marked[start] = true;

    int count = 0;
    while(!q.empty()) {

        int node = q.front();
        q.pop();

        for (auto i:graph[node]) 
        {
            if (!marked[i]) 
            { 
                marked[i] = true; 
                q.push(i);
                count++; 
            } 
        } 
    }

    cout << count * 2 << endl;
}

int main() {
    
    int t, n, v, a, x1, x2;

    cin >> t;

    while(t--) {
        cin >> n >> v >> a;

        vector <int> xs[v];

        while(a--) {
            cin >> x1 >> x2;
            xs[x1].push_back(x2);
            xs[x2].push_back(x1);
        }

        bfs(xs, v, n);
    }

    return 0;
}