#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

void bfsFloodFill(char matrix[][1000], int n, int m, vector<ii> xs) {
    queue <ii> q;
    int row[] = {1, -1, 0, 0};
    int col[] = {0, 0, 1, -1};

    for(auto x:xs) {
        q.push(x);
        while(!q.empty()) {

            ii node = q.front();
            q.pop();

            int x = node.first;
            int y = node.second;

            if(matrix[x][y] == 'A') matrix[x][y] = 'T';

            if(x >= 0 && x < n && y >=0 && y < m) {    
                for(int i = 0; i < 4; i++) if(matrix[x+row[i]][y+col[i]] == 'A') q.push(ii(x+row[i], y+col[i]));
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
        
            cout << matrix[i][j];
        }
        cout << endl;
    }
}


int main() {

    int n = 1, m = 1;
    char matrix[1000][1000], aux;
    ii init;
    vector <ii> xs;

    while(n || m) {
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> aux;
                matrix[i][j] = aux;

                if(matrix[i][j] == 'T') xs.push_back(ii(i, j));
            }
        }

        bfsFloodFill(matrix, n, m, xs);
        if(n || m) cout << endl;
        xs.clear();
    }


    return 0;
}