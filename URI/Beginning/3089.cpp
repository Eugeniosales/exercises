#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, aux;
    vector <int> xs;

    while(scanf("%d", &n) && n) {
        int x = n * 2;
        while(x--) {
            cin >> aux;
            xs.push_back(aux);
        }

        sort(xs.begin(), xs.end());

        int mx = -1;
        int mn = 100000000;
        for(int i = xs.size()/2; i < xs.size(); i++) {
            mx = max(mx, (xs[i] + xs[xs.size() - i -1]));
            mn = min(mn, (xs[i] + xs[xs.size() - i -1]));
        }

        cout << mx << " " << mn << endl;

        xs.clear();
    }
    
    return 0;
}