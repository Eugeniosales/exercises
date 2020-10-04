#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> ii;

bool mx(string a, string b) {
    return a.length() > b.length();
}

int main() {
    string s, aux;
    vector <string> xs;
    int n;
    cin >> n;
    n++;
    while(n--){
        
        getline(cin, s); 
        
        stringstream ss(s);
        while(ss >> aux) {
            xs.push_back(aux);
        }

        stable_sort(xs.begin(), xs.end(), mx);
        
        for(int i = 0; i < xs.size(); i++) {
            cout << (i == (xs.size()-1)? xs[i] + "\n": xs[i] + " ");
        }
    
        xs.clear(); 
    }
    
    return 0;
}