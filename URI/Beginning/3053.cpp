#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, num;
	char pos;

	cin >> n >> pos;

	while(n--) {
		cin >> num;
		if(num == 1 && pos == 'A') pos = 'B';
		else if(num == 1 && pos == 'B') pos = 'A';
		else if(num == 2 && pos == 'B') pos = 'C';
		else if(num == 2 && pos == 'C') pos = 'B';
		else if(num == 3 && pos == 'C') pos = 'A';
		else if(num == 3 && pos == 'A') pos = 'C';
	}

	cout << pos << endl;

	return 0;
}