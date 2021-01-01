#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c, num;
    vector <int> xs[1000];

    cin >> n;
    bool isFirst = true;
    while(n--) {
        cin >> m >> c;
        while(c--) {
            cin >> num;
            int key  = num % m;
            xs[key].push_back(num);
        }

        if(isFirst) isFirst = false;
        else printf("\n");

        for(int i = 0; i < m; i++) {
            cout << i << " -> ";
            for(auto x:xs[i]) cout << x << " -> ";
            printf("\\\n");

        }
        
        for(auto& x:xs) x.clear();

    }
    return 0;
}