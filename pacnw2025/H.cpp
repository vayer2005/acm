#include <bits/stdc++.h>

using namespace std;

#define int long long



signed main() {
    int n;
    cin >> n;
    vector<int> a(n+1,0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<int> pref(n+1,0);

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i];
    }

    vector<int> sol;

    for (int i = 1; i <= n; i++) {
        int ind = ((i + 1)/2);
        int med = a[ind];
        int sumsm = pref[ind];
        int sumlrg = pref[i] - pref[ind];

        int numsm = ind;
        int numlr = i-ind;

        int ans = abs(sumsm - med*numsm) + abs(sumlrg - med*numlr);
        sol.push_back(ans);
    }
    
    reverse(sol.begin(), sol.end());
    for (int x : sol) {
        cout << x << "\n";
    }

}