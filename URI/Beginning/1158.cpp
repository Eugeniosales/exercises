#include <bits/stdc++.h>

using namespace std;

void solve(int x, int y){

    int aux = x, count = 0;

    while(y--){
        count += aux;
        aux += 2;
    }

    cout << count << endl;
}

int main() {
    int n, x, y;
    cin >> n;
    while(n--) {
        cin >> x >> y;

        x % 2 == 0? solve(x + 1, y) : solve(x, y);
    }
    return 0;
}