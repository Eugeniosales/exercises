#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, p, aux;
    string fruit;
    float price;
    map <string, float> xs;

    cin >> n;

    while(n--) {
        cin >> m;
        while(m--) {
            cin >> fruit >> price;
            xs[fruit] = price;
        }

        cin >> p;

        float total = 0.0;
        while(p--) {
            cin >> fruit >> aux;
            total += (float) xs[fruit] * aux;
        }

        printf("R$ %.2f\n", total);
        xs.clear();
    }
    return 0;
}