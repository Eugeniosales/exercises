#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

double final(int w, int a, int b) {
    return ((((w * a) + ((100-w) * b))+1.0)/100);
}

int main() {
    int n, a, b, count;
    double nota;
    vector <ii> xs;
    priority_queue <int> g;
    cin >> n;

    while(n--) {
        cin >> a >> b;
        xs.push_back(ii(a, b));
    }

    for(int w = 0; w < 101; w++) {
        count = 0;
        for(auto x:xs) {
            nota = final(w, x.first, x.second);
            if(nota >= 60) count++;
        }
        g.push(count);
    }

    cout << g.top() << endl;

    return 0;
}