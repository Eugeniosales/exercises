#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    long long int  n, aux, xs = 0, ans=1, mx =-1;
    cin >> n;
    while(n--){       
        cin >> aux;        
        if(aux >= xs && xs) ans++;
        else ans = 1;
        xs = aux;
        mx = max(mx, ans);
    }
 
    cout << mx << endl;
 
    return 0;
}