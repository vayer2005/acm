#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll l; ll r;
    cin >> l >> r;
    if (l == 1 && r == 1) {
        cout << 1 << endl;
        return;
    }
    
   cout << r-l << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}