#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ll n;
    cin >> n;
    ll a[n];
    ll tot = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        tot+=a[i];
    }

    tot /= 2;

    sort(a, a+n);
    reverse(a, a+n);

    ll dp[n+1][tot+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <=n; i++) {
        dp[i][0] = 1;
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        ll val = a[i-1];
        for (int j = 0; j <= tot; j++) dp[i][j] = dp[i-1][j];

        for (ll j = tot; j >= 0; j--) {
            if (j + val > tot) {
                res += dp[i-1][j];
            } else {
                dp[i][j+val] += dp[i-1][j];
            }
        }
    }

    cout << res << endl;
}