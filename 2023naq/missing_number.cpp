#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define int long long
#define double long double

using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int mod = 9302023;
const int NUM = 1e6+5; 
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
vector<int> lp, sieve;
vector<int> pr;
vi pow2(2e5+1, 0);
vector<int> power;
vector<int> fact(2e5 + 5, 0);
vector<int> inv_fact(2e5 + 5, 0);


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vi res;

    for (int l = 1; l <= 5; l++ ){
        if(l > s.size()) continue;
        int curr = stoi(s.substr(0, l));
        int strt = curr;
        int idx = 0;
        int skipped = 0;
        int numsk;
        while (idx < n) {
            if (skipped > 1) break;
            string look = to_string(curr);
            if (idx + look.size() > n) {
                numsk = -1;
                skipped++;
            } else if (look == s.substr(idx, look.size())) {
                curr++;
                idx = idx + look.size();
            } else {
                numsk = curr;
                skipped++;
                curr++;
            }
        }
        if (skipped == 1 && numsk != -1) {
            res.pb(numsk);
        } else if (skipped == 0) {
            if (strt > 1) res.pb(strt-1);
            if (curr <= 99999) res.pb(curr);
        }
    }   

    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}