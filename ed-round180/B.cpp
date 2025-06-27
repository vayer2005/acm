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

    int minOps=1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (abs(a[i]-a[j]) <= 1) {  
                minOps = min(minOps, abs(i-j)-1);
            }
        }

        for (int j = i+1; j < n-1; j++) {
            int fir = a[j];
            int sec = a[j+1];
            if (fir > sec) swap(fir, sec);
            if (a[i] >= fir && a[i] <= sec) {
                minOps = min(minOps, abs(i-j));
            }
        }

        for (int j = 1; j < i; j++) {
            int fir = a[j];
            int sec = a[j-1];
            if (fir > sec) swap(fir, sec);
            if (a[i] >= fir && a[i] <= sec) {
                minOps = min(minOps, abs(i-j));
            }
        }
        
    }

    if (minOps == 1e9) {
        cout << "-1\n";
        return;
    }
    cout << minOps << endl;


}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}