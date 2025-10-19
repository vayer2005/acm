#include <bits/stdc++.h>

#define int long long

using namespace std;

int dp[10000000];
int vis[10000000];
int tot = 0;
int need;

int dfs(int idx, vector<int> &pref) {
    if (idx >= pref.size()) return 0;
    if (vis[idx] == 1) return dp[idx];
    vis[idx] = 1;
    int nd = pref[idx] + need;
    if (tot - pref[idx] < need) {
        dp[idx] = tot-pref[idx];
        return dp[idx];
    } else {
        auto it = lower_bound(pref.begin(), pref.end(), nd);
        if (it == pref.end() || *it != nd) {
            dp[idx] = -1;
            return dp[idx];
        } else {
            int nind = it-pref.begin();
            dp[idx] = dfs(nind, pref);
        }
    }

    return dp[idx];


}


void solve() {
    int k, n;
    cin >> k >> n;

    vector<int> a(n);

  
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));

    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
        mx = max(mx, a[i]);
    }

    if (k <= 0 || tot % k != 0) {
        cout << "NO\n";
        return;
    }
    
    need = tot/k;
    if (mx > need) {
        cout << "NO\n";
        return;
    }
    vector<int> pref(n);
    pref[0]= a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + a[i];
    }

    


    //cout << need << endl;
    for (int i = 0; i < n; i++) {
        //cout << i << " " << dfs(i, pref) << endl;
        if (pref[i] <= need && dfs(i, pref) != -1 && (dfs(i, pref)+pref[i] == need)) {
            cout << "YES\n";
            return;
        }
    }

    int curr = 0;
    int used = 0;
    for (int i = 0; i < n; i++) {
        if (curr + a[i] == need) {
            used++;
        } else if (curr + a[i] > need) {
            cout << "NO\n";
            return;
            
        } else {
            curr += a[i];
        }
    }

    if (used == k) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";




}

signed main() {

    solve();
    return 0;
}