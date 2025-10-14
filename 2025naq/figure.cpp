#include <bits/stdc++.h>
 
using namespace std; 
#define int long long
#define double long double

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int sumsq=0;
    int sum=0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
        sumsq += a[i] * a[i];
    }   

    double mean = (sum)/(k*1.0);
    double ans = sumsq - (mean * sum * 2) + mean*mean*k;

    for (int i = k; i < n; i++) {
        //cout << ans << endl;
        int torem = a[i-k];
        int toadd = a[i];

        sum = sum - torem + toadd;
        sumsq = sumsq - torem * torem + toadd*toadd;
        double nans = (double)sumsq - sum*sum / (double)k;

        ans = min(ans, nans);
    }

    cout << fixed << setprecision(9) << ans << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}