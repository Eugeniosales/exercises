#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, aux, count;
    vector <int> xs;

    while(scanf("%d", &n) && n) {
        int x = n;
        count = 0;
        int pos = 1;
        while(x--) {
            int q = 3;
            bool v = true;
            while(q--) {
                cin >> aux;
                xs.push_back(aux);
            }

            if(xs[pos] != 0) {
                if(pos == 1 && xs[0] == 0) {
                    count++;
                    pos = 0;
                }

                if(pos == 1 && xs[2] == 0) {
                    count++;
                    pos = 2;
                }

                if(pos == 0 && xs[1] == 0) {
                    count++;
                    pos = 1;
                }

                if(pos == 0 && xs[2] == 0) {
                    count+=2;
                    pos = 2;
                }

                if(pos == 2 && xs[1] == 0) {
                    count+=1;
                    pos = 1;
                }

                if(pos == 2 && xs[0] == 0) {
                    count+=2;
                    pos = 0;
                }
            }

            xs.clear();
        }

        cout << count << endl;

    }

    return 0;
}