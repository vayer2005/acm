#include <bits/stdc++.h>

using namespace std;
#define int long long

const double EPS = 1e-9;
const double PI = 3.141592653589793;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int c[m];
    for (int i = 0; i < m; i++) {
        cin >>c[i];
    }
    sort(c, c+m);
    int ovr = c[0];
    int rnb = 1;
    for (int i = m-1; i >= 1; i--) {
        if (ovr <= 2) break;
        if (c[i] == n) continue;
        if ((ovr-1 + c[i]) > n) {
            rnb++;
            ovr = (ovr-1 + c[i])%n;
        }
    }
    cout << rnb << endl;
}