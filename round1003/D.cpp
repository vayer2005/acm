#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(b, b+m);
    ll prev = -1000000001;
    for(int i = 0; i < n; i++) {

        int l = 0; int r = m-1;

        while (l < r) {
            int mid = (l + r)/2;

            if (b[mid] - a[i] >= prev) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        ll bv = b[l];
        if (!(bv-a[i] >= prev || a[i] >= prev)) {
            cout << "NO\n";
            return;
        }
        if (bv-a[i] >= prev && a[i] >= prev) {
            prev = min(bv-a[i], a[i]);
        } else if (a[i] >= prev) {
            prev = a[i];
        } else if (bv-a[i] >= prev) {
            prev = bv-a[i];
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