#include <bits/stdc++.h>
 
using namespace std; 
#define int long long
#define double long double

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = a[0]/3;
    int mx = a[n-1]/3;

    int sec = a[1] - 2*mn;

    cout << mn << " " << sec << " " << mx << endl; 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}