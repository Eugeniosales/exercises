#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, b, h, w, coast, aux, total;
    
    while(cin >> n >> b >> h >> w){
        int mn = 10000000;
        while(h--){
            cin >> coast;
            for(int i = 0;i < w;i++){
                cin >> aux;
                if(aux >= n && (n * coast) <=  mn) mn = n * coast;
            }
        }
        if(mn <= b) cout << mn << endl;
        else cout << "stay home" << endl;
    }
    
    return 0;
}