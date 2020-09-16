#include <bits/stdc++.h>

using namespace std;

int main() {
    int aux, count;

    cin >> aux;

    count = aux;

    for(int i = 0; i < 10; i++) {

        printf("N[%d] = %d\n", i, count);
        count = (count * 2);
    }
}