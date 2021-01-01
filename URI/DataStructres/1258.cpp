#include <bits/stdc++.h>

using namespace std;

struct Shirt {
    string name;
    string color;
    char size;
};

bool rule(Shirt& a, Shirt& b) {
    return a.color != b.color ? a.color < b.color : a.size != b.size ? a.size > b.size : a.name < b.name;
}

int main() {
    int n;
    string name, color;
    char size;
    vector <Shirt> xs;

    bool isFirst = true;
    while(scanf("%d", &n) && n) {

        while(n--) {
            while(getline(cin, name))
                if(name != ""){
                break;
            }
            cin >> color >> size;
            xs.push_back({ name, color, size });
        }

        if(isFirst) isFirst = false;
        else cout << endl;

        sort(xs.begin(), xs.end(), rule);
        for(auto x:xs) cout << x.color << " " << x.size << " " << x.name << endl;

        xs.clear();
    }
    return 0;
}