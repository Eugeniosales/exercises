#include <bits/stdc++.h>

using namespace std;

int n, matrix[10][10];


void print() {
    for(int  i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int border(int x, int y) {
    return x < 0 || x > 9 || y < 0 || y > 9? -1:1;
}

int check(int x, int y) {
    return matrix[x][y] == 1? -1:1;
}

int main() {
    int d, l, c, r;

    cin >> n;

    int ans = 1;

    for(int  i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) {
            matrix[i][j] = 0;
        }
    }

    while(n--) {
        cin >> d >> l >> r >> c;

        r--;
        c--;

        int ax = r;
        int ay = c;
        
        if(d == 0) {
            
            for(int i = c; i < (l+c); i++) {
                if(border(r, i) == 1 && check(r, i) == 1) {
                    matrix[r][i] = 1;
                } else {
                    ans = -1;
                }
            } 
        } else {

            for(int i = r; i < (l+r); i++) {
                if(border(i, c) == 1 && check(i, c) == 1) {
                    matrix[i][c] = 1;
                } else {
                    ans = -1;
                }
            }
        }
    }

    cout << (ans == 1? 'Y':'N') << endl;


    return 0;
}