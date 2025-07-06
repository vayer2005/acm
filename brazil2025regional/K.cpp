#include <bits/stdc++.h>

using namespace std;
#define int long long

const double EPS = 1e-9;
const double PI = 3.141592653589793;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int a[n];
    int tsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tsum += a[i];
    }

    if (tsum %2 == 1)
    {
        cout <<"-1\n";
        return 0;
    }

    tsum /=2;

    int dp[10001][n];

    memset(dp, 0, sizeof(dp));
    sort(a, a+n);

    dp[a[0]][0] = 1;
    dp[0][0] = 1;
    

    for(int i = 1; i < n; i++) {
        for (int j = 0; j < 10001; j++) {
            if (dp[j][i-1] == 1) {
                dp[j][i] = 1;
                dp[j+a[i]][i] = 1;
            }
            if (j == tsum && dp[j][i] == 1) {
                vector<int> res;
                int look = tsum;
                int ind = i;
                while (look != 0) {
                    if (ind == 0) {
                        res.push_back(a[ind]);
                        break;
                    }
                    if (dp[look][ind-1] == 1) {
                        ind-=1;
                    } else {
                        look -= a[ind];
                        res.push_back(a[ind]);
                        ind-=1;
                    }
                }

                vector<int>rest;
                ind = 0;
                reverse(res.begin(), res.end());
                for (int k = 0; k < n; k++) {
                    if (a[k] == res[ind]) ind++;
                    else {
                        rest.push_back(a[k]);
                    }
                }

                int asum = 0; int bsum = 0;
                int i1 = 0;
                int i2 = 0;
                for (int k = 0; k < n; k++) {
                    if (asum <= bsum) {
                        cout << res[i1] << " ";
                        asum += res[i1];
                        i1++;
                    } else {
                        cout << rest[i2] << " ";
                        bsum += rest[i2];
                        i2++;
                    }
                }
                return 0;
            }
        }
    }
    
    cout << "-1\n";
    return 0;
}