#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    string a; string b; string c;

    cin >> a >> b >> c;

    int n = a.size(); int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if (i < n) {
                int cost = (a[i] != c[i+j]) ? 1 : 0;
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost);
            }

            if (j < m) {
                int cost = (b[j] != c[i+j]) ? 1 : 0;
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + cost);
            }
        }
    }

    cout << dp[n][m] << endl;




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