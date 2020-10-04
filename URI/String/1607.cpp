#include <bits/stdc++.h>

using namespace std;

int solve(string a, string b) {
    int count = 0;
    for(int i = 0; i < a.size(); i++) {
        count += a[i] <= b[i]? b[i] - a[i] : b[i] - a[i] + 26;
    }

    return count;
}

int main() {
    int n;
    string a, b;

    cin >> n;
    while(n--) {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}