#include <bits/stdc++.h>

using namespace std;

void solve(int aux) {

    int d = 5;
    int count = 0;
    while(d--) {
        count += aux;
        aux += 2;
    }
    cout << count << endl;
}


int main() {
    int aux = 1;
    while(1) {
        cin >> aux;
        if(!aux) return 0;        
        aux%2 == 0? solve(aux) : solve(aux+1);
    }
}