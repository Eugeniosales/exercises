#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p;
    string st;
    map <string, int> xs;

    cin >> n;
    while(n--) {
        cin >> p;
        for(int i = 0; i < p; i++) {
            cin >> st;
            xs[st]++;
        }
        cout << (xs[st] == p? st:"ingles") << endl;
        xs.clear();
    }
}