#include <bits/stdc++.h>

using namespace std;

vector <int> xs (100, 0);

int fib(int n){
    if(!xs[n]){
        if(n<2) xs[n] = 1;
        else xs[n] = fib(n-1) + fib(n-2);
    }
    return xs[n];
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}