#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


signed main() {
    int n;
    cin >> n;
    vector<int> t(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
    }
    double er;
    cin >> er;
    const double EPS = 1e-9;

    int ok[n][n];
    memset(ok, 0, sizeof(ok));
    const double INF = 1e100;
    for (int i = 0; i < n-1; i++) {
        double L = -INF;
        double R = INF;
        for (int j = i+1; j < n; j++) {
            if (j > i+1) {
                int k = j-1;
                double newL = (p[k]-er-p[i])/(t[k]-t[i]);
                double newR = (p[k]+er-p[i])/(t[k]-t[i]);
                L = max(L, newL);
                R = min(R, newR);
            }
            double slope = (p[j] - p[i]) / double(t[j] - t[i]);
            if (slope >= L - EPS && slope <= R + EPS)
                ok[i][j] = 1;
        }
    }

    vector<int> dp(n, 1e6);
    dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            if (ok[i][j]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << dp[0]+1 << endl;
}