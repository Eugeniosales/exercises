#include <bits/stdc++.h>

using namespace std;

bool solve(int num) {
    int count = 0;

    for(int i = 1; i < num;i++) {
        if(num % i == 0) {
            count+= i;
        } 
    }

    return count == num? true:false;
}

int main() {
    int n, aux;

    cin >> n;

    while(n--) {
        cin >> aux;
 
        if(solve(aux)) cout << aux << " eh perfeito" << endl;
        else cout << aux << " nao eh perfeito" << endl;
    }

    return 0;
}