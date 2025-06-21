 
#include <algorithm>
#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
#define MAXN 200010
#define MOD 998244353
typedef long long ll;
typedef pair<ll, ll> pi;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt; tt = 1;
    while (tt--) {

        ll a, b; cin >> a >> b;
        ll ans = 0;
        ll on = 1;
        ll bk = 0;
        for (ll i = 60; i >= 0; i--) {
            ll idx = (on << i);
            if ((a & idx) == (b & idx)) ans |= (a & idx);
            else {
                for (ll j = i; j >= 0; j--) {
                    ll temp = (on << j);
                    if ((ans | temp) >= a && (ans | temp) <= b) bk = j;
                }
                break;
            }
        }
        if (ans >= a && ans <= b) cout << ans << "\n";
        else cout << (ans | (on << bk)) << "\n";
    }
}