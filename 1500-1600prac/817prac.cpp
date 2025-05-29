#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int a[1001][1001];
    int dp[1001][1001];

    int n; int q; 
    cin >> n >> q;

    int hi, wi;

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            a[i][j] = 0;
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        cin >> hi >> wi;
        a[hi][wi] += hi * wi;
    }


    

    for(int i = 1; i < 1001; i++) {
        for(int j = 1; j < 1001; j++) {
            //change dp state
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
        }
    }


    int hs, ws, hb, wb;
    for(int i = 0; i< q; i++) {
        cin >> hs >> ws >> hb >> wb;

        if (hs+1 >= hb || ws+1 >= wb) {
            cout << 0 << endl;
            continue;
        }

        int res = dp[hb-1][wb-1] - dp[hb-1][ws] - dp[hs][wb-1] + dp[hs][ws];
        cout << res << endl;
    }
	
}
 
signed main()
{
	int t; cin >> t;
    while (t--) {
        solve();
    }
    
}