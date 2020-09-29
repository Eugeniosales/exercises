#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, code, aux;
    char st[1000];
    map <int, string> xs;

    cin >> n;

    while(n--) {
        scanf("%d %[^\n]", &code, st);
        xs[code] = st;
    }

    while(scanf("%d", &aux) != EOF) {
        
        cout << (xs[aux].length()? xs[aux] : "Music not found") << endl;
    }
 
    return 0;
}