#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> t(n), p(n);
    for(int i=0;i<n;++i) cin >> t[i] >> p[i];
    long long delta; cin >> delta;

    const double INF = 1e100;
    const double EPS = 1e-9;

    // ok[i][j] == true if segment (i,j) is δ-feasible
    vector<vector<char>> ok(n, vector<char>(n, 0));

    for(int i=0;i<n-1;++i){
        double L = -INF, R = INF; // current admissible slope interval
        for(int j=i+1;j<n;++j){
            if(j>i+1){
                int k=j-1; // newly added interior point
                long long dx = t[k]-t[i];
                double low  = (double)(p[k]-delta - p[i]) / dx;
                double high = (double)(p[k]+delta - p[i]) / dx;
                L = max(L, low);
                R = min(R, high);
            }
            double slope = (double)(p[j]-p[i]) / (t[j]-t[i]);
            if(slope + EPS >= L && slope - EPS <= R) ok[i][j] = 1;
        }
    }

    const int BIG = n+5;
    vector<int> dp(n, BIG);
    dp[0] = 1; 
    for(int j=1;j<n;++j){
        for(int i=0;i<j;++i){
            if(ok[i][j]) dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    cout << dp[n-1] << '\n';
    return 0;
}