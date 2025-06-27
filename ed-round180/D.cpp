#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 2e5+5;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

vector<int> targ(200001,0);
map<int, vector<int>>adj;

vector<int> color(200001,-1);


void dfs(int val, int prev) {
    if (adj[val].size() == 2) {
        for (int x : adj[val]) {
            targ[val] = x;
            if (x != prev) {
                dfs(x, val);
            }
        }
    } else {
        for (int x : adj[val]) {
            if (x != prev) dfs(x, val);
        }
    }
}

void dfs2(int val, int prev) {
    bool res = true;
    for (int x : adj[val]) {
        if (x != prev) {
            color[x] = !color[val];
            dfs2(x, val);
        }
    }
}

void solve() {
    adj.clear();
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        targ[i] = 0;
        color[i] = -1;
    }

    int u, v;
    vpi edges;

    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u,v});
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        if (targ[i] != 0) {
            cout << "YES\n";
            color[i] = 0;
            bool done = false;
            for (int x : adj[i]) {
                if (!done) {
                    color[x] = 0;
                    done = true;
                } else {
                    color[x] = 1;
                }
                dfs2(x, i);
            }
            for (auto v : edges) {
                if (v.first == i || v.second == i) {
                    int other;
                    if (v.first == i) {
                        other = v.second;
                    } else {
                        other = v.first;
                    }
                    if (color[other] == 1) {
                        cout << i << " " << other << endl;
                    } else {
                        cout << other << " " << i << endl;
                    }
                } else {
                    if (color[v.first] == 0) {
                        cout << v.first << " " << v.second << endl;
                    } else {
                        cout << v.second << " " << v.first << endl;
                    }
                }
            }
            return;

        }
    }

    cout << "NO\n";

    
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}