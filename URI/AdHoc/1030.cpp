#include <bits/stdc++.h>

using namespace std;


int solve(int a, int b, int c) {
    return pow(a*b*c, 1.0/3.0);
}

int main() {
    int a, b, c;

    while(1) {
        cin >> a >> b >> c;
        if(!(a || b || c)) break;
        cout << solve(a, b, c) << endl;
    }
    return 0;
}