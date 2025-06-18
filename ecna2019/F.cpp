#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


int main() {
    int n;
    cin >> n;

    int left = n;

    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int prev[n];
    int next[n];

    prev[0] = n-1;
    next[n-1] = 0;
    for (int i = 0; i < n-1; i++) {
        next[i] = i+1;
    }
    for (int i = 1; i < n; i++) {
        prev[i] = i-1;
    }

    int ind = 0;
    while (left > 1) {
        int jumps = (a[ind]-1) % left;
        int used = 0;
        while (used < jumps) {
            used++;
            ind = next[ind];
        }

        left--;
        int temp = prev[ind];
        int nxt = next[ind];
        ind = nxt;
        next[temp] = nxt;
        prev[nxt] = temp;

    }

    cout << ind + 1 << endl;
  


}