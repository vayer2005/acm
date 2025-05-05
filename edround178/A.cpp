#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    ll a; ll b; ll c;

    cin >> a >> b >> c;
    c -= abs(a-b);
    ll res = max(a, b);

    ll diff = c - res;
    if (diff < 0) {
        cout << "NO\n";
    } else if (diff % 3 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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