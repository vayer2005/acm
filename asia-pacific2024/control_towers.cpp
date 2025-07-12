#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve()
{   
    int n, m;
    cin >> n >> m;

    string grid[n];
    int dp[n][m][5];
    int row[n][5];
    int col[m][5]; 
    int rem[n];
    int cem[m];
    memset(dp, 0, sizeof(dp));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(rem, 0, sizeof(rem));
    memset(cem, 0, sizeof(cem));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    } 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dp[i][j][4] = 1;
                row[i][4]++;
                col[j][4]++;
                rem[i]++;
                cem[j]++;
            }
        }
    }

    for (int k = 3; k >= 1; k--) {
        cout << k << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    dp[i][j][k] = row[i][k+1] + col[j][k+1] - 2 * dp[i][j][k+1];
                    row[i][k] += dp[i][j][k];
                    col[j][k] += dp[i][j][k];
                }
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {    
                ans += dp[i][j][1] - (2*dp[i][j][2] - dp[i][j][3]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int p = rem[i];
        if (p >= 3) ans -= p * (p - 1) * (p - 2);
    }
    for (int j = 0; j < m; j++) {
        int p = cem[j];
        if (p >= 3) ans -= p * (p - 1) * (p - 2);
    }

    cout << ans << endl;





}  

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}