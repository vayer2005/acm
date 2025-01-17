#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



void solve() {
    int n;
    cin >> n;
    int res[n];

    res[0] = 1;
    res[1] = 1;
    res[n-1] = 1;
    for(int i = 2; i < n-1; i++) {
        res[i] = i;
    } 

    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}



int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}