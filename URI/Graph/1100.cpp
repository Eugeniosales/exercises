#include <bits/stdc++.h>
#define SIZE 8

using namespace std;

typedef pair<int, int> ii;

int col[] = {2, 2, -2, -2, 1, 1, -1, -1};
int row[] = {-1, 1, -1, 1, -2, 2, -2, 2};

struct position {
    ii point;
    int dist;
};

bool isValid(int x, int y){
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int parents(map <ii, ii> parent, ii dest){
    vector <ii> xs;
    ii p = parent[dest];

    while(p.first != -1 && p.second != -1){
        xs.push_back(p);
        p = parent[p];
    }

    //for(auto x:xs) cout << (char) (x.first + 97) << (char) (x.second + 49) << endl;

    return xs.size();
}

int bfs(int graph[SIZE][SIZE], ii origin, ii dest) {
    queue <position> q;
    bool marked[SIZE][SIZE];
    map <ii, ii> parent;
    
    memset(marked, false, sizeof(marked));

    position source = {origin, 0};
    marked[origin.first][origin.second] = true;
    parent[origin] = ii(-1, -1);
    q.push(source);

    while(!q.empty()) {
        position node = q.front();
        q.pop();

        if(dest.first == node.point.first && dest.second == node.point.second) {
            return parents(parent, dest);
        }
        
        for(int i = 0; i < 8; i++) {
            int x = node.point.first + row[i];
            int y = node.point.second + col[i];

            if(isValid(x, y) && !marked[x][y]) {
                marked[x][y] = true;
                position next = {ii(x, y), node.dist + 1 };
                parent[ii(x, y)] = ii(node.point.first, node.point.second); 
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int xs[SIZE][SIZE];
    char a[10], b[10];

    while(cin >> a >> b) {
        ii origin = ii(((int) a[0] - 97), (int) a[1] - 49);
        ii dest = ii(((int) b[0] - 97), (int) b[1] - 49);

        printf("To get from %s to %s takes %d knight moves.\n", a, b, bfs(xs, origin, dest));
    }

    return 0;
}