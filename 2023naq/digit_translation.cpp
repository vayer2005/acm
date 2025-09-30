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

    int dp[n+1];
    int ways[n+1];

    memset(dp, 0, sizeof(dp));
    ways[n] = 1;

    vector<string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "zero"};

    for (int i = n-1; i >= 0; i--) {
        dp[i] = dp[i+1] + 1;
        ways[i] = ways[i+1];
        for (string w : words) {
            if (i + w.size() <= n) {
                bool works = true;
                for (int k = 0; k < w.size(); k++) {
                    if (s[i+k] != w[k]) works = false;
                }
                if (works) {
                    if (dp[i + w.size()] + 1 == dp[i]) {
                        ways[i] = (ways[i] + ways[i + w.size()]) % mod;
                    } else if (dp[i + w.size()] + 1 < dp[i]) {
                        dp[i] = dp[i + w.size()] + 1;
                        ways[i] = ways[i + w.size()];
                    }
                }
            }
        }
    }

    cout << dp[0] << "\n" << ways[0] << endl;

    

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}