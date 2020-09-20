#include <bits/stdc++.h>
 
using namespace std;
 
// TODO: Make a priority queue to put the even or odd numbers in front, each queue per participant
 
struct greater_odd_first{
    bool operator()(int a, int b) const{
        if(a%2==0){
            if(b%2)
                return true;
        }
        else if(b%2==0)
            return false;
    }
};
 
 
struct greater_even_first{
    bool operator()(int a, int b) const{
        if(a%2==0){
            if(b%2)
                return false;
        }
        else if(b%2==0)
            return true;
    }
};
 
int main() {
	int t, n;
	string num;
	priority_queue <int, vector<int>, greater_odd_first> r;
	priority_queue <int, vector<int>, greater_even_first> q;
 
	cin >> t;
 
	while(t--){
		cin >> n >> num;
		int x = 1;
		for(auto i:num) {
			int aux = (i - '0');
			if(x % 2) r.push(aux);
			else q.push(aux);
			x++;
		}
 
		if(r.size() > q.size()) cout << (r.top()%2?1:2) << endl;
		else cout << (q.top()%2?1:2) << endl;
 
		while(!q.empty()) q.pop();
		while(!r.empty()) r.pop();
	}
 
	return 0;
}