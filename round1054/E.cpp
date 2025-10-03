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
    int n, k, l, r;
 
    cin >> n >> k >> l >> r;
 
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
 
    int b = 0;
    int c = 0;
    map<int,int> moccur;
    map<int,int> xoccur;
    int nums = 0;
    int pmin = 0;
    int pmax = 0;
    //l = max(l, k);
 
    for (int i = 0; i < n; i++) {
        moccur[a[i]]++;
        xoccur[a[i]]++;
        if (moccur[a[i]] == 1) nums++;
        if (nums == k) {
            pmin = i;
            pmax = i;
            break;
        } 
    }
    for(int i = pmin + 1; i < n; i++) {
        xoccur[a[i]]++;
        pmax++;
        if (xoccur[a[i]] == 1) {
            xoccur[a[i]]--;
            pmax--;
            break;
        }
    }
 
    if (nums < k) {
        cout << "0\n";
        return;
    }
 
    //cout << pmin << " " << pmax << endl;
    int ans = 0;
 
    ans += max(0LL, min(pmax, r-1) - max(pmin, l-1)+1LL);
 
    //cout << ans << endl;
    
    for (int i = 1; i < n; i++){
        moccur[a[i-1]]--;
 
        if (moccur[a[i-1]] == 0) {
            nums--;
            int cm = pmin;
            for (int j = cm + 1; j < n; j++) {
                moccur[a[j]]++;
                if (moccur[a[j]] == 1) {
                    nums++;
                    pmin = j;
                    break;
                }
            }
        }
 
        xoccur[a[i-1]]--;
        int sn = 0;
        if (xoccur[a[i-1]] == 0) {
            int cp = pmax;
            for (int j = cp+1; j < n; j++) {
                xoccur[a[j]]++;
                pmax++;
                
                if (xoccur[a[j]] == 1) {
                    sn++;
                }
                if (sn == 2) {
                    xoccur[a[j]]--;
                    pmax--;
                    break;
                }
            }
        }
 
        if (nums < k) {
            break;
        }
        ans += max(0LL, min(pmax, i+r-1) - max(pmin, i+l-1)+1LL);
    }
 
    cout << ans << endl;
    
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}