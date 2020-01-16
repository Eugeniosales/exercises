#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, aux;
    vector <int> xs;
    cin >> n;
    aux = n;

    if(n==1){ cout << 1 << endl << 1 << endl; return 0; }

    for(int i = 1; i < aux; i++){
        if( (n-i) > i ){
            xs.push_back(i);
            n-=i;
        } else{
            xs.push_back(n);
            break;
        }
    }

    cout << xs.size() << endl;
    for(auto x:xs) cout << x << " ";
    cout << endl;
    return 0;
}