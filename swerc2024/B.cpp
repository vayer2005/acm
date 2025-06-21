#include <bits/stdc++.h>
#define mp make_pair
#define int long long

using namespace std;


signed main() {
    int n, k;
    cin >> n >> k;
    int a[n+1];
    int b[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a, a+n+1);

    int pref2[n+1];
    int pref[n+1];
    pref[0] = 0;
    pref2[0] = 0;
    for(int i = 1; i <= n; i++) {
        pref2[i] = pref2[i-1] + a[i] * a[i];
        pref[i] = pref[i-1] + a[i];
    }

    int dp[k][n+1];
    int prev[k][n+1];
    memset(dp, 0, sizeof(dp));
    memset(prev, 0, sizeof(prev));

    for(int i = 1; i <= n; i++) {
        int val = a[i];
        dp[0][i] = pref2[i] - 2 * val * pref[i] + val * val * i;

        for (int j = 1; j < k; j++) { 
            dp[j][i] = 1e18;
            for (int z = 1; z <= i; z++) {
                int cost = pref2[i] - pref2[z-1] - 2 * val * (pref[i] - pref[z-1]) + val * val * (i-z+1);
                if (cost + dp[j-1][z-1] < dp[j][i]) {
                    dp[j][i] =cost + dp[j-1][z-1];
                    prev[j][i] = z-1;
                }
            }
        }
    }
    
    int ind = n;
    int j = k-1;
    map<int,int> x;
    while (ind > 0) {
        int til = prev[j][ind];
        for (int i = ind; i > til; i--) {
            x[a[i]] = a[ind];
        }
        ind = til;
        j-=1;
    }

    for (int i = 1; i <= n; i++) {
        cout << x[b[i]] << " ";
    }
    cout << endl;



}


