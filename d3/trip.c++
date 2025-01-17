#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 
void solve() {

    ll l, r;
    cin >> l >> r;


    ll k = 31 - __builtin_clz(l ^ r);
    ll a = l | ((1 << k)-1);
    ll b = a + 1; 
    ll c;
    if (a == l) {
        c = r;
    } else {
        c = l;
    }
    //c = (a == l ? r : l);
    cout << a << " " << b << " " << c << "\n";

}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
 
    while (t--) {
        solve();
    }
}