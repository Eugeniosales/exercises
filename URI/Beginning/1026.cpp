#include <bits/stdc++.h>

using namespace std;

int main () {

    long unsigned int a, b;

    while((scanf("%lu%lu", &a, &b)) != EOF) {
        cout << (a^b) << endl;
    }

    return 0;
}