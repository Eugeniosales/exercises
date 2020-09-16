#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int main() {
    int aux, res = MAX, num, pos=-1;

    cin >> aux;

    for(int i = 0; i < aux; i++) {
        cin >> num;
        pos = num < res? i:pos;
        res = num < res? num:res;
    }

    printf("Menor valor: %d\nPosicao: %d\n", res, pos);

    return 0;
}