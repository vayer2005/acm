#include <bits/stdc++.h>

using namespace std;

void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> & x, int lo, int hi) {
    int p = lo+1;
    for( int i=lo+1; i <= hi; i++ ) {
      if( x[i] < x[lo] ) { swap(x[p], x[i]); ++p; }
      swap(x[lo], x[p - 1]);
    }
    return p-1;
}




int main() {
    vector<int> arr = {5,4};
    partition(arr, 0,1);
    for (int i = 0; i < 2; i++) {
        cout <<arr[i] << " ";
    }
    cout << endl;
    return 1;
}