#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    ll n, p, l, t;
    cin >> n >> p >> l >> t;

    ll le = 0; ll r = n;

    while (le <= r) {
        ll mid = (le + r) /2;
        
        ll tot = (mid * l) + t * min(((n-1)/7)+1, 2 * mid);
        //cout << mid << ": " << tot << endl;
        if (tot >= p) {
            r=mid-1;
        } else {
            le = mid + 1;
        }
    }

    cout << n- r-1 << endl;



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