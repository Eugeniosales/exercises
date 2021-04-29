#include <bits/stdc++.h>

using namespace std;

int solve(vector <int> xs, int n, int m) {
    if(n == 0 || m == 0)
        return 0;
    if(n >= xs[m-1])
        return solve(xs, n - xs[m-1], m) + 1;
    return solve(xs, n, m -1);
}

int solve_3(vector <int> xs, int n, int m) {
    int ans = 0;
    while(n > 0 && m >= 0) {
        if(xs[m-1] <= n) {
            ans++;
            n-=xs[m-1];
        } else {
            m--;
        }
    }

    return ans;
}

int main() {
    int n;
    vector <int> xs { 1, 5, 10, 20, 100 };
    

    cin >> n;
    cout << solve(xs, n, xs.size()) << endl;
    return 0;
}