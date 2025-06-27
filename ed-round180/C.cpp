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
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int res = 0;
    int big = a[n-1];

    for (int i = n-1; i >= 2; i--) {
        int needed = a[i];
        if (big - needed > needed) needed = big - needed;
        needed++;
        int l = 0; int r = i-1;

        while (l <= r) {
            if (a[l] + a[r] >= needed) {
                res += r-l;
                r--;
            } else l++;
        }
    }

    cout << res << endl;

}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}