#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

ll arr[300007];
map<ll, ll> vis;
map<ll, vector<ll>>grp;
ll sol = 0;

ll dfs(ll added) {
    if (vis.find(added) != vis.end()) {
        return vis[added];
    }
    ll maxv = 0;
    for(int i = 0; i < grp[added].size(); i++) {
        ll val = grp[added][i];
        if (val != 0) {
            maxv = max(maxv, val + dfs(added + val));
        }
    }
    vis[added] = maxv;
    return maxv;

}


void solve() {
    vis.clear();
    grp.clear();
    int n;
    cin >> n;
    for(int i =0; i < n; i++) {
        cin >> arr[i];
    }

    ll needed[n];

    for(int i = 0; i < n; i++) {
        needed[i] = arr[i] + i - n;
    } 

    for(int i = 0; i < n; i++) {
        if (needed[i] >= 0) { 
            grp[needed[i]].push_back(i);
        }
    }

    cout << dfs(0) + n << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}