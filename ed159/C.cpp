#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;

    ll a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    sort(a, a+n);
    ll diff[n-1];

    for (int i = n-2; i >= 0; i--) {
        diff[i] = a[n-1]-a[i];
    }

    ll g = 0;
    for (int i = 0; i < n-1; i++) {
        g = gcd(diff[i], g);
    }

    
    vector<ll> away;

    for (int x : diff) {
        away.push_back(x/g);
    }

    reverse(away.begin(), away.end());

    ll ans = 0;
    for(ll x : away) {
        ans += x;
    }
    
    ll v = 1;
    ll res;
    
    for (int i = 0; i < n-1; i++) {
        if (away[i] != v) {
            res = v;
            break;
        }
        v++;
    }

    ans = v + accumulate(away.begin(), away.end(), 0LL);
    cout << ans << endl;
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