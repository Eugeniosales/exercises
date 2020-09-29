#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int c, int x) {
    return abs(x -a) +  pow(abs(x - b), 2) + pow(abs(x-c), 3);
}

typedef pair<int, int> ii;

int main() {
    int a, b, c, n =3;
    vector <int> xs;
    priority_queue <ii, vector<ii>, greater<ii>> pq;
    cin >> a >> b >> c;
    for(int i = 1; i < 100; i++) {
        int res = solve(a, b, c, i);
        pq.push(ii(res, i));
    }

    cout << pq.top().second << endl;

    return 0;
}