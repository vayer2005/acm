#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    int high = 2*n;
    int low = 1;
    int upper[n];
    int lower[n];

    int i = 0;
    while (i < n) {
        upper[i] = high;
        lower[n-i-1] = high - 1;
        high -= 2;
        i+=2;
    }

    i = 1;
    while (i < n) {
        upper[i] = low+1;
        lower[n-i-1] = low;
        low += 2;
        i+=2;
    }

    for(int i = 0; i < n; i++) {
        cout << upper[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << lower[i] << " ";
    }
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}