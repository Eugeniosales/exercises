#include<bits/stdc++.h> 
using namespace std; 
  
int steiner(int n) 
{ 
    if (n <= 1) 
        return 2; 
    return steiner(n-1) + n; 
} 
  
int main () 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> m;
    while(m--) {
        cin >> n; 
        cout << steiner(n) << "\n";
    } 
    return 0; 
} 
