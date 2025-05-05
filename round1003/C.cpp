#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int m;
    cin >> n >> m;
    ll a[n];
    ll b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> b;

    ll prev = -1000000001;
    for(int i = 0; i < n; i++) {
        if (!(b-a[i] >= prev || a[i] >= prev)) {
            cout << "NO\n";
            return;
        }
        if (b-a[i] >= prev && a[i] >= prev) {
            prev = min(b-a[i], a[i]);
        } else if (a[i] >= prev) {
            prev = a[i];
        } else if (b-a[i] >= prev) {
            prev = b-a[i];
        }
    }
    cout << "YES\n";


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