#include <bits/stdc++.h>


#define int long long

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    int a[n];

    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    sort(a,a+n);
    reverse(a, a+n);

    int md = tot/x;
    int ans = 0;
    for (int i = 0; i < min(md, n); i++) {
        ans += a[i];
    }

    int r = n-1;
    int l = min(md-1, n-1);

    while(l >= 0 && r >= 0) {
        
    }

    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}