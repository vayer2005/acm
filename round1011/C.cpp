#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    ll x; ll y;
    cin >> x >> y;

    if (x == y) {
        cout << -1 << endl;
        return;
    }
    ll val = 1;
    while(val <= max(x, y)) {
        val *= 2;
    }

    ll k = val - max(x,y);
    cout << k << endl;




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