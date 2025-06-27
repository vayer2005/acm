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

void solve() {
    int a, x, y;
    cin >> a >> x >> y;

    for (int i = 1; i<=100; i++) {
        if (i == a) continue;
        if (abs(x-i) < abs(x-a) && abs(y-i) < abs(y-a)) {
            cout << "YES\n";
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