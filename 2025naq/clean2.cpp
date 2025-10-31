#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int long long

int n, m, k;

int works(int s, vector<vector<int>>& pref, vector<vector<int>> &obs) {
    vector<vector<int>> valid(n+1, vector<int>(m+1,0));
    
    int mxi = n-s+1;
    int mxj = m-s+1;

    int tv = 0;
    int strti = -1; int strtj = -1;
    for (int i = 1; i <= mxi; i++) {
        for (int j = 1; j <= mxj; j++) {
            int fini = i+s-1;
            int finj = j+s-1;
            if (obs[i][j] == 1) continue;
            int numo = pref[fini][finj] - pref[i-1][finj] - pref[fini][j-1] + pref[i-1][j-1];
            if (numo == 0) {valid[i][j] += 1; tv++; strti = i; strtj = j;}
            
        }
    }

    if (tv == 0) return 0;
    queue<pair<int,int>> q;
    q.push({strti, strtj});


    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int i = curr.first; int j = curr.second;
        int endi = i + s -1; int endj = j + s-1;

        if (i <= 0 || i > mxi || j <= 0 || j > mxj || valid[i][j]==0 || valid[i][j] == 2) continue;
        valid[i][j] = 2;
        q.push({i+1, j});
        q.push({i, j+1});
        q.push({i-1, j});
        q.push({i, j-1});
    }

    vector<vector<int>> diff(n+2, vector<int>(m+2,0));

    for (int i = 1; i <= mxi; i++) {
        for (int j = 1; j <= mxj; j++) {
            if (valid[i][j] == 2) {
                diff[i][j] += 1;
                diff[i+s][j] += -1;
                diff[i][j+s] += -1;
                diff[i+s][j+s] += 1; 
            } else if (valid[i][j] == 1) {
                return 0;
            }
        }
    }

    int run = 0;
    for (int i = 1; i <= n; i++) {
        run = 0;
        for (int j = 1; j <= m; j++) {
            run += diff[i][j];
            diff[i][j] = run + diff[i-1][j];
        }
    }

    int can = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (obs[i][j]) continue;
            if (diff[i][j] > 0) can++;
        }
    }

    if (can + k == n * m) return 1;
    return 0;

}



void solve() {
    cin >> n >> m >> k;

    int ro, c;
    vector<vector<int>> obs(n+1, vector<int>(m+1, 0));
    vector<vector<int>> pref(n+1, vector<int>(m+1, 0));


    for (int i = 0; i < k; i++) {
        cin >> ro >> c;
        obs[ro][c] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + obs[i][j];
        }
    }

    int l = 1; int r = min(n,m);

    int ans = -1;
    while (l <= r) {
        int mid = (l+r)/2;

        if (works(mid, pref, obs)) {
            ans = max(mid, ans);
            l = mid + 1;
        } else {
            r = mid-1;
        }
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
    

}