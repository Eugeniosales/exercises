#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

bool compare(ii& a, ii& b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
    
}

int main() {
    string w;
    map <int, int> xs;
    vector <ii> mp;

    bool isFirst = true;
    while(cin >> w) {
        for(int x:w) {
            ++xs[x];
        }
        for(auto x:xs) mp.push_back({ x.second, x.first });

        sort(mp.begin(), mp.end(), compare);

        if(isFirst) isFirst = !isFirst;
        else cout << "\n";

        for(auto x:mp) cout << x.second << " " << x.first << endl;

        xs.clear();
        mp.clear();
    }
    return 0;
}