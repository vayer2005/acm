#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double EPS = 1e-9;
const double PI = 3.141592653589793;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int ans;
    for (int i = 0; i <= k; i++) {
        // i = speech length
        int t = n * i + (n-1);
        if (t <= k) ans = i;
        else break;
    }
    cout << ans << endl;
}