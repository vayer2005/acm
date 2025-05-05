#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; cin >> n;
    vector <int> a(n);
    long long ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i]; cnt += (a[i] & 1);
    }
    if (!cnt || cnt == n) {
        cout << *max_element(a.begin(), a.end()) << '\n';
    } else {
        cout << ans - cnt + 1 << '\n';
    }



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