#include <bits/stdc++.h>

using namespace std;

int main() {
    char s;
    string num;

    while(1) {
        cin >> s >> num;
        int s_ = s - '0';
        int num_ = num[0] - '0';
        if(s_ == 0 && num_ == 0) break;

        vector <char> xs;

        for(auto x:num) {
            if(x != s) xs.push_back(x);
        }

        bool zeros = true;

        for(auto x:xs) {
            if(x != '0') zeros = false;
        }
        
        if(zeros) cout << 0;
        else {
            bool print_zero = false;
            for(auto x:xs) {
                if(x != '0') print_zero = true;

                if(print_zero) cout << x;
            }
        }

        cout << endl;

        xs.clear();
        num.clear();

    }
    return 0;
}