// Graph - level 3

#include <bits/stdc++.h>

using namespace std;

void bfs(vector <int> graph[], int size, int start ) {

    bool marked[size];
    queue <int> q;

    for(int i = 0; i < size; i++) marked[i] = false;

    int count = 0;
    for(int k = 0; k < size; k++) {
        
        if(!marked[k]) {
            q.push(k);
            marked[k] = true;

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for (auto i = graph[node].begin(); i != graph[node].end(); ++i) 
                {
                    if (!marked[*i]) 
                    {
                        count++;
                        marked[*i] = true; 
                        q.push(*i); 
                    }
                } 
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