#include <bits/stdc++.h>

using namespace std;

int solve(int h1, int m1, int h2, int m2) {
    int mt1 = h1 * 60 + m1;
    int mt2 = h2 * 60 + m2;

    if (mt2 < mt1) return (24*60+mt2)-mt1;
    else  return abs(mt1-mt2);
}

int main() {
    int h1 = 1, m1 = 1, h2 = 1, m2 = 1;

    while(1) {
        scanf("%d%d%d%d", &h1, &m1, &h2, &m2);
        if(!(h1 || m1 || h2 || m2)) break;
        else cout << solve(h1, m1, h2, m2) << endl;
    }

    return 0;
}