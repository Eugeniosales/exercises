#include <bits/stdc++.h>

using namespace std;

// Time: O(log n)
// Space: O(log n)

bool  binarySearch(const vector <int> arr, const int num, int left, int right, int& x) {
    if(left > right)
        return false;
    
    x++;
    int mid = (left + right) / 2; 

    if(arr[mid] == num) 
        return true;
    else if(arr[mid] > num) 
        return binarySearch(arr, num, left, mid-1, x);
    else
        return binarySearch(arr, num, mid+1, right, x);
}


int main() {
    vector <int> xs { 1, 3, 4, 5, 7, 9, 10, 14 };

    int count = 0;
    if(binarySearch(xs, 1, 0, xs.size(), count)) cout << "Found" << endl;
    else cout << "Not found" << endl;

    cout << "Steps: " << count << endl;

    return 0;
}