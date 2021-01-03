#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    map <char, int> xs;
    vector <char> ss;

    cin >> n;

    while(n--) {
        while(getline(cin, s))
            if(s != ""){
            break;
        } 

        int mx = 0;
        for(auto x:s) {
            if(isalpha(x)) {
                char aux = tolower(x);
                ++xs[aux];
                mx = max(mx, xs[aux]);
            }
        }

        for(auto x:xs) {
            if(x.second == mx) {
                ss.push_back(x.first);
            } 
        }

        sort(ss.begin(), ss.end());

        for(auto x:ss) cout << x;
        cout << endl;

        ss.clear();
        xs.clear();
    }
    return 0;
 }