#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    ll n; ll x; ll k;
    string s;
    cin >> n >> x >> k >> s;

    for (int i = 0; i < n; ++i) {
      x += (s[i] == 'L' ? -1 : +1);
      --k;
      if (!x) break;
    }

    ll ans = 0;
    if (!x) {
      ans = 1;
      for (int i = 0; i < n; ++i) {
        x += (s[i] == 'L' ? -1 : +1);
        if (!x) {
          ans += k / (i + 1);
          break;
        }
      }
    }
    cout << ans << '\n';
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