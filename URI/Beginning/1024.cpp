#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    string xs;
    stack <int> st;
    
    cin >> n;
    for(int k = 0; k <= n; ++k) {

        getline(cin, xs);

        for(auto i:xs) {
            int aux = (int) i;

            if(aux > 64 && aux < 96 || aux > 96 && aux < 123) {
                st.push(aux+3);
            } else {
                st.push(aux);
            } 
            
        }
        
        int i = 0;
        while(!st.empty()) {
            if(i >= (xs.size() / 2)) cout << (char) (st.top() - 1);
            else cout << (char) st.top();
            if (i==xs.size() - 1) cout << "\n";

            st.pop();
            i++;
        }
        xs.clear();
    }
    return 0;
}