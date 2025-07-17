#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    int s[m+1];
    int l[m+1];

    for (int i = 1; i <= m; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
    }

    int ways[m+1][m+1];

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            int s1 = s[i]; int l1 = l[i];
            int s2 = s[j]; int l2 = l[j];

            ways[i][j] = ways[j][i] = s1*l2 + s2*l1 + s1 * s2;
        }
    }

    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        dp[i][n] = 1;
    }

    for (int d = n-1; d >= 0; d--) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (ways[i][j] != 0) {
                    dp[i][d] = (dp[i][d] + ((ways[i][j] * dp[j][d+1]) % mod))%mod;
                }
            }
        }
    }

    cout << dp[1][0] << endl;






}