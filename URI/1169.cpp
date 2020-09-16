#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, aux;

    cin >> n;

    while(n--) {
        cin >> aux;
        printf("%lld kg\n", (long long) (pow(2, aux)/12000) );
    }
    return 0;
}