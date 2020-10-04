#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nc, n, h;
    vector <int> xs;

    cin >> nc;
    while(nc--) {
        cin >> n;
        while(n--) {
            cin >> h;
            xs.push_back(h);
        }
        sort(xs.begin(), xs.end());
        int aux = xs.back();
        xs.pop_back();
        for(auto x:xs) cout << x << " ";
        cout << aux << endl;
        xs.clear();
    }
}