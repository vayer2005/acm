#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    if (n%p == 0) {
        if ((n/p) * q == m) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "YES\n";
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