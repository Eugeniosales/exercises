#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string a, b;

    cin >> n;
    while(n--) {
        cin >> a >> b;

        int count = b.size();

        int ans = 0;
        if(a.size() >= b.size()) {
            int sz = a.size() - b.size();
            for(int i = sz; i < a.size(); i++) {
                if(a[i] == b[i - sz]) ans++;
            }
        }

        cout << (count == ans?"encaixa":"nao encaixa")  << endl;
    }
    return 0;
}