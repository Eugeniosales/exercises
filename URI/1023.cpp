#include <bits/stdc++.h>

using namespace std;

int main () {

    int n = 1, x, y;
    vector <map<int, int>> xs;
    map <int, int> mp;

    int count = 1;
    while(n) {
        cin >> n;

        if(!n) break;

        float people = 0.0, liters = 0.0;

        for(int i = 0 ; i < n; i++) {
            cin >> x >> y;

            mp[y/x] = mp[y/x] + x;

            people += (float) x;
            liters += (float) y;
        }

        cout <<  "Cidade# " << count << ":" << endl;

        for(auto w:mp) {
            cout << w.second << "-" << w.first << "  ";
        }

        cout << endl;

        printf("Consumo medio: %.2f m3.\n", floor(100 *liters/people) /100);

        count++;

        mp.clear();
    }
    
    return 0;
}