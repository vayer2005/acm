#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

#define pb push_back

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int sum = 0;
    int sumsq = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
        sumsq += a[i] * a[i];
   }

    double mean = sum/(k*1.0);
    //cout << prevans << " " << prevsum << " " << mean << endl;
    double ans = sumsq - (sum * mean*2) + k * mean*mean;
    //cout << ans << endl;
    for (int i = k; i < n; i++) {
        int toadd = a[i];
        int torem = a[i-k];
        sum = sum - torem + toadd;
        double nmean = sum/(k*1.0);

        sumsq = sumsq - torem*torem + toadd * toadd;
        double nans = sumsq - sum * nmean * 2 + k * nmean*nmean;
        ans = min(ans, nans);
    }

    cout << fixed << setprecision(9) << ans << endl;
}


signed main() {
    solve();
    return 0;
}