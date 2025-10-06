#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define int long long

using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int mod = 1e9+7;
const int NUM = 1e6+5; 
const int N = 2e5+5;
const double EPS = 1e-7;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
vector<int> lp, sieve;
vector<int> pr;
vi pow2(2e5+1, 0);
vector<int> power;
vector<int> fact(2e5 + 5, 0);
vector<int> inv_fact(2e5 + 5, 0);



void solve(int t) {
    int n;
    cin >> n;

    vector<double> a(n+1);
    vector<double> b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    double l = 0;
    double r = 10000000;

    for (int i = 1; i <= n; i++) {
        double mxp = (i*1.0)/a[i];
        double mnp = (i*1.0)/b[i];
        
        l = max(l, mnp);
        r = min(r, mxp);
        
        if (l > r + EPS) {
            cout << fixed << setprecision(8) << "Case #" << t+1 << ": " << -1 << endl;
            return;
        }
    }
    cout << fixed << setprecision(8) << "Case #" << t+1 << ": " << l << endl;
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
   
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}