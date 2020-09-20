#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t, n, r, q, aux;
	string num;
 
	cin >> t;
 
	while(t--){
		cin >> n >> num;
		r = 2; q = 1;
		int x = 1;
		for(auto i:num) {
			aux = (i - '0');
			if(x % 2) {
				r = aux%2? aux: r;
			} 
			else {
				if(!(aux%2)) q = aux;
			}
			x++;
		}
 
		if(n == 1) cout << (aux%2? 1:2) << endl;
		else if(n%2) cout << (r%2? 1:2) << endl;
		else  cout << (q%2? 1:2) << endl;

	}
 
	return 0;
}