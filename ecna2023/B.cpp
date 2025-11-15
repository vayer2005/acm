#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double


double dp[2001][101];

int s; 
double cst(int l, int r, vector<double>& p1, vector<double>& p2) {
    double sumsq = p2[r] - p2[l-1];
    double sm = p1[r] - p1[l-1];
    int n = r-l+1;

    double mn = sm / n;

    double mid = -2 * mn* sm;
    double fin = n * (s/2.0) * (s/2.0);

    double res = sumsq + mid + n * mn * mn +fin;
    return res;
}

signed main() {
    int n, m, k;
    cin >> m >> n >> k >> s;
    memset(dp, 0, sizeof(dp));
    vector<double> a(n+m+1);
    vector<double> pref(n+m+1,0);
    vector<double> pref2(n+m+1,0);

    for (int i =1; i <= m+n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());   

    pref[1] = a[1];
    pref2[1] = a[1] * a[1];
    for (int i = 2; i <= n+m; i++) {
        pref[i] = pref[i-1] + a[i];
        pref2[i] = pref2[i-1] + a[i] * a[i];
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n+m; i++) {
            if (j == 1) {
                dp[i][j] = cst(1,i, pref, pref2);
            } else {
                dp[i][j] = 1e18;
                for (int z = 1; z < i; z++) {
                    dp[i][j] = min(dp[i][j], dp[z][j-1] + cst(z+1, i, pref, pref2));
                }
            }
            
        }
    }

    cout << fixed << setprecision(10) << dp[n+m][k] << endl;


}