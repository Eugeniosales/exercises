// Bakery - Graph - Level 1

#include <bits/stdc++.h>
#define MAX 1000000001

using namespace std;

int solve(vector <int> graph[], map <pair<int, int>, int> hs, map <int, bool> st, vector<int>st2) {

    int sm = MAX;
    for(int i:st2) {
        for(auto k:graph[i]) {
            if(!st[k]) {
                int aux = min(hs[{ i, k }], hs[{ k, i }]);
                sm = min(sm, aux);
            }
        }
    }

    return sm < MAX? sm : -1;
}

int main() {

    int nodes, edge, storages;
    int node1, node2, length;
    int storage;
    map <pair<int, int>, int> hs;
    map <int, bool> st;
    vector <int> st2;

    cin >> nodes >> edge >> storages;

    vector <int> xs[nodes*2];

    while(edge--) {
        cin >> node1 >> node2 >> length;
        xs[node1].push_back(node2);
        xs[node2].push_back(node1);
        if(hs[make_pair(node1, node2)] == 0) { 
            hs[make_pair(node1, node2)] = length;    
            hs[make_pair(node2, node1)] = length;    
        } else {
            hs[make_pair(node1, node2)] = min(hs[make_pair(node1, node2)], length);
            hs[make_pair(node2, node1)] = min(hs[make_pair(node2, node1)], length);
        }
    }
    

    while(storages--) {
        cin >> storage;
        st[storage] = true;
        st2.push_back(storage);
    }

    cout << solve(xs, hs, st, st2) << endl;

    return 0;
}