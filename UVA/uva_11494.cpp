#include <bits/stdc++.h>

using namespace std;

int main(){
    int x1, x2, y1, y2, res;
    while(cin >> x1 >> y1 >> x2 >> y2, y2 && x2){
        if(x1 == x2 && y1 == y2) res = 0;
        else if( abs(x1-x2) == abs(y1-y2) ) res = 1;
        else if(x1 == x2 || y1 == y2) res = 1;
        else res = 2;
        cout << res << endl;
    }
    return 0;
}