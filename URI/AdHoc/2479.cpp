#include <bits/stdc++.h>
#define MAX 100000.0

using namespace std;
 
int main() {
 
	int n, s = 0, nn = 0;
	char carac[1000], name[1000];
	priority_queue <string, vector<string>, greater<string> > pq;
	cin >> n;
	while(n--){
		scanf("%s%s", carac, name);
		pq.push(name);
		carac[0] == '+'? ++s:++nn;
	}

	while(!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	printf("Se comportaram: %d | Nao se comportaram: %d\n", s, nn);
    return 0;
}
