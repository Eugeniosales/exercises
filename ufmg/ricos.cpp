#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    int spend = 0;
    cin >> a >> b;

    while(1) {
        if(a == b) {
            cout << spend << endl;
            break;
        }
        else if (a > b) {
            spend += (b + 1);
            a-= (b + 1);
        }
        else {
            spend += (a + 1);
            b-= (a + 1);
        }
    }
    return 0;
}