#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n;

    while(n--) {
 
        while(getline(cin, s))
            if(s != ""){
            break;
        } 
        
        int mid = (s.size() / 2) - 1;

        for(int i = mid; i >= 0; i--) printf("%c", s[i]);
        for(int i = s.size() - 1; i >= mid+1; i--) printf("%c", s[i]);
        printf("\n");
    }

    return 0;
}