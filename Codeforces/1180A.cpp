#include <bits/stdc++.h>
 
using namespace std;
 
int solve(int n){
    if(n==1) return 1;
    return (((n-1) * 2) * n) + 1;
}
 
int main(){    
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}