#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void solve(string str, int l, int c) {
    stringstream s(str);
    string ans;

    int line = 0;
    int res = 1;
    while(s >> ans) {
        int sz = ans.size();

        if(sz + line < c) {
            line+= sz + 1;
        } else if(sz + line == c) {
            line+= sz;
        } else {
            line = 0;
            res++;
            line+= sz + 1;
        }
    }


    int pages = res % l == 0? res / l:(res / l) + 1;
    cout << pages << endl;
}

int main() {
    int n, l, c;
    string w;

    while(scanf("%d %d %d", &n, &l, &c) != EOF) {
        cin.ignore();

        getline(cin, w);

        solve(w, l, c);

    }

    return 0;
}