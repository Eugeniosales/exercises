#include <bits/stdc++.h>

using namespace std;

int fib_memo(int n, int memo[]) {
    if(n == 1 || n == 2) return 1;
    if(memo[n]) return memo[n];

    memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo);
    
    return memo[n];
}

int fib(int n) {
    if(n == 1 || n == 2) return 1;

    return fib(n-1) + fib(n-2);
}

int fib_tabulation(int n) {
    int fib[n];
    fib[1] = 1;
    fib[2] = 1;

    for(int i = 3; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

typedef pair<int, string> ii;

int main() {
    int memo[100];
    memset(memo, 0, sizeof(memo));

    //cout << fib_memo(3, memo) << endl;
    cout << fib_tabulation(3) << endl;

    return 0;
}