#include <bits/stdc++.h>

using namespace std;

int calcula(string s,int m){ 
    int r=0; 
    for(int i=0;i<s.size();i++){ 
        r= (((10%m)*r) % m + (s[i]-'0')) % m; 
    }

    return r;
}

bool leap(string n){
    return calcula(n, 400) == 0 || calcula(n, 100) != 0 &&calcula(n, 4) == 0;
}

bool hol(string n) {
    return calcula(n, 15) == 0;
}

bool bul(string n) {
    return calcula(n, 55) == 0 && leap(n);
}
 
int main() {
    string n;
    bool isFirst = true;

    while(cin >> n) {

        bool l = leap(n);
        bool h = hol(n);
        bool b = bul(n);

        if(isFirst) isFirst = !isFirst;
        else cout << endl;

        if(!l && !h && !b) cout << "This is an ordinary year." << endl;
        else {
            if(l) cout << "This is leap year." << endl;
            if(h) cout << "This is huluculu festival year." << endl;
            if(b) cout << "This is bulukulu festival year." << endl;
        }
    }

    return 0;
}