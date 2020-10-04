#include <bits/stdc++.h>
#define loop(x,n) for(int x = 0; x < n; ++x)

using namespace std;

typedef pair<int, int> ii;

typedef vector<ii> vt;

struct node {
    ii point;
    int dist;
};

int row[] = {1, -1, 0, 0};
int col[] = {0, 0, 1, -1};

bool validCoordinate(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int bfsMaze(char maze[][1000], ii source, vt dest, int n) {
    queue <node> q;
    bool marked[n][n];
    
    memset(marked, false, sizeof(marked));

    node s = {source, 0};

    q.push(s);

    while(!q.empty()) {
        
        node top = q.front();
        q.pop();

        for(auto x:dest) {

            if(top.point.first == x.first && top.point.second == x.second) {
                return top.dist;
            }
        }

        for(int i = 0; i < 4; i++) {
            int x = top.point.first + row[i];
            int y = top.point.second + col[i];

            if(!marked[x][y] && validCoordinate(x, y, n) && maze[x][y] != '#' ) {
                node unit = { ii(x, y), top.dist + 1 };
                marked[x][y] = true;
                q.push(unit);       
            }
        }
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    char x, maze[1000][1000];
    vector <ii> source;
    vector <ii> dest;

    cin >> t;
    for(int l = 1; l <= t; l++) {
        cin >> n;
        loop(i, n) {
            loop(j, n) {
                cin >> x;
                maze[i][j] = x;
                if(x == 'A' || x == 'B' || x == 'C') {
                    source.push_back(ii(i, j));
                }

                if(x == 'X') dest.push_back(ii(i, j));
            }
        }
        
        int mx = -1;

        for(auto x:source) {
            mx = max(mx, bfsMaze(maze, x , dest, n));
        } 

        mx == -1? printf("Case %d: trapped\n", l) : printf("Case %d: %d\n", l, mx);

        source.clear();
        dest.clear();
    }

    return 0;
}