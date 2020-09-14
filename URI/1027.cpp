#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, a, b;

    while((scanf("%d", &n)) != EOF) {
        int count = 0, ap = -1;
        for(int i = 0; i< n; i++) {
            cin >> a >> b;

            if(a > ap && abs(0+b) == 1) {
                //cout << a << "  " << b << endl;
                ap = a;
                count++;
            }
        }
        cout << (count? count - 1 : 0) << endl;
    }

    return 0;
}