#include <bits/stdc++.h>

using namespace std;

int stair_way(int n) {
    if( n < 0)
        return 0;
    if(n == 0) {
        return 1;
    }

    return stair_way(n-1) + stair_way(n-3) + stair_way(n-5);
};

int stair_way_bottom_up(int n) {
    int stair[n+1];
    stair[0] = 0;
    stair[1] = 1; // 1; ->
    stair[2] = 1; // 1, 1; -> 1
    stair[3] = 2; // 1, 1, 1; 3; -> 2
    stair[4] = 2; // 1, 1, 1, 1; 1, 3; -> 2
    stair[5] = 3; // 1, 1, 1, 1, 1; 1, 1, 3; 5; ->3

    for(int i = 5; i <=n; i++)
        stair[i] = stair[i-1] + stair[i-3] + stair[i-5];

    return stair[n];

};

int main () {
    cout << stair_way_bottom_up(7) << endl;
    return 0;
};