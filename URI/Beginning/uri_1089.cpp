#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, nex;
    vector <int> xs;

    while(cin >> n, n){
        while(n--){
            cin >> nex;
            xs.push_back(nex);
        }
        xs.push_back(xs[0]);
        
        int count = 1; bool flag, ch;
        xs[0] < xs[1]? flag = true: flag = false;
        ch = flag;
        
        for(int i = 2; i < xs.size(); i++){
            if(xs[i] > xs[i-1] && !flag){
                count++; flag = !flag;
            } 
            if(xs[i] < xs[i-1] && flag){
              count++; flag = !flag; 
            } 
        }
        // To check the end and the beginning
        if(ch == flag) count--;

        cout << count << endl;
        xs.clear();
    }

    return 0;
}