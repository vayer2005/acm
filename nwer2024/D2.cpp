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
 
    vector<ll> dp(tot+1);
    sort(a, a+n);
    reverse(a, a+n);
    dp[0] = 1;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = tot; j >= 0; j--) {
            if (j + a[i] > tot) {
                res += dp[j];
            } else {
                dp[j+a[i]] += dp[j];
            }
        }
    }
 
    cout << res << endl;
    
}