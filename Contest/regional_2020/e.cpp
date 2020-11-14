#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii; 

vector <int> mp(1000, 0);

struct Party {
    int anf;
    int id_i;
    int id_f;
};

void bfs(vector <int> graph[], int size, Party p, map <int, int> age) {

    vector <bool> marked(size, false);
    queue <int> q;

    q.push(p.anf);
    marked[p.anf] = true;
    mp[p.anf]++;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto i:graph[node])  
        {
            if (!marked[i] && age[i] >= p.id_i && age[i] <=p.id_f) 
            { 
                marked[i] = true;
                q.push(i);
                mp[i]++;
            } 
        } 
    }
}

int main() {
    int n, m, a, b, o, l, r;
    vector <int> xs[1000];
    map <int, int> age;
    vector <Party> pt;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        xs[b-1].push_back(i);
        xs[i].push_back(b-1);
        age[i] = a;
    }

    while(m--){
        cin >> o >> l >> r;
        bfs(xs, n, { o - 1, l, r }, age);
    }

    for(int i = 0; i < n; i++) {
        cout << mp[i] << (i == (n-1)? "\n":" " );
    }

    return 0;
}