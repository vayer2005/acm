#include <bits/stdc++.h>
#define mp make_pair
#define int long long
 
using namespace std;
 
 
void solve() {
    int n;
    cin >> n;
 
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    if (n == 2) {
        if (a[0] <= a[1]) {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    if (n%2 == 1) {
        cout << "YES\n";
        return;
    }
 
    for (int i = 1; i < n-1; i++) {
        if (a[i-1] > a[i]) {
            a[i+1] += a[i-1] - a[i];
            a[i] = a[i-1];
        }
        if (i%2 == 1) {
            a[i] = 0;
        } 
    }
    if (a[n-2] <= a[n-1]) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
}