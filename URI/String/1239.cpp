#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    stack <char> i, b;

    while(getline(cin, s)){
        int count_i = 0, count_b = 0;

        for(auto x:s) { 
            if(x == '_' && count_i == 0) {
                cout << "<i>";
                count_i++;
            } else if(x == '_' && count_i > 0) {
                cout << "</i>";
                count_i--;
            } else if(x == '*' && count_b == 0) {
                cout << "<b>";
                count_b++;
            } else if(x == '*' && count_b > 0) {
                cout << "</b>";
                count_b--;
            } else if (x != '_' && x != '*') {
                cout << x;
            }
        }

        cout << endl;
    } 
}