#include <bits/stdc++.h>

using namespace std;

int main() {
    string xs;
    while(getline(cin, xs)) {
        bool flag = true;
        for(int i = 0; i < xs.size(); i++){
            if(xs[i] != ' ') {
                if(flag) {
                    cout << (char) toupper(xs[i]);
                    flag = false;
                } else {
                    cout << (char) tolower(xs[i]);
                    flag = true;
                }
            } else cout << " ";
        }
        cout << endl;
    }
    return 0;
}