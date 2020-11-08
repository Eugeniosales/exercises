#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, m;

    while(scanf("%d %d", &h, &m) != -1) {
        string hh = h * 12/360 > 9? to_string(h * 12/360) : "0" + to_string(h * 12/360);
        string mm = m * 60/360 > 9? to_string( m * 60/360) : "0" + to_string( m * 60/360);
        cout << hh << ":" << mm << endl;
    }
    return 0;
}