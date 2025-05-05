
#include <bits/stdc++.h>

using namespace std;

void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> & x, int lo, int hi) {
    int p = lo+1;
    for( int i=lo+1; i <= hi; i++ )
      if( x[i] < x[lo] ) { swap(x[p], x[i]); ++p; }
    swap(x[lo], x[p-1]);
    return p-1;
}
void qsort(vector<int> & x, int lo, int hi) 
{
  if (lo < hi) {
    int pivot = partition(x, lo, hi); 
    qsort(x, lo, pivot-1);
    qsort(x, pivot+1, hi);
  }
}

int main () {
    vector<int> arr = {4, 5, 3, 1,4,21, 7};

    qsort(arr, 0, 6);

    for(int i = 0; i <7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}