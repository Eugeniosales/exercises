#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, vf, vg;
    while((scanf("%d %d %d", &d, &vf, &vg)) == 3) cout << ( ((double) 12/vf) >= ((double) sqrt((d*d + 144))/vg)? "S": "N" ) << endl;
}