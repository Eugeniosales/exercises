#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int rule(ii& a, ii& b) {
    int moda = a.first;
    int modb = b.first;
    int na = a.second;
    int nb = b.second;

    if(moda == modb) {
        if(abs(na) % 2 == abs(nb)%2) return na%2 != 0? na > nb: nb > na;
        return abs(na) % 2  > abs(nb) % 2;
    }

   return moda < modb;
}

int main() {
    int n, m, num;
    vector <ii> xs;
    while(1) {
        cin >> n >> m;

        if(!(n || m)) {
            cout << n << " " << m << endl;
            break;
        }

        int nn = n;
        while(n--) {
            cin >> num;
            int mod = num % m;
            xs.push_back({ mod, num });
        }

        sort(xs.begin(), xs.end(), rule);

        cout << nn << " " << m << endl;
        for(auto x:xs) cout << x.second << endl;

        xs.clear();
    }
    
    return 0;
}