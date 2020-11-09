#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, x2, y1, y2, n, ax, ay;

    int i = 1;

    while(1) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        if(!(x1 || x2 || y1 || y2)) break;

        cin >> n;
        int ans = 0;
        
        if(x1 > x2) {
            int aux = x1;
            x1 = x2;
            x2 = aux;
        }

        if(y1 > y2) {
            int aux = y1;
            y1 = y2;
            y2 = aux;
        }

        while(n--) {
            cin >> ax >> ay;

            if(ax >= x1 && ax <= x2 && ay >= y1 && ay <= y2) ans++;
        }

        printf("Teste %d\n", i);
        cout << ans << endl;

        i++;
    }
    return 0;
}