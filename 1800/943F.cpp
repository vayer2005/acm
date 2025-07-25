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
const int mod = 998244353;
const int NUM = 1000030;
const int N = 2e5+5;
const double EPS = 1e-9;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
vector<int> lp, sieve;
vector<int> pr;
vector<int> power;
vector<int> fact(2e5 + 5, 0);
void initpow(int x)
{
    power.resize(NUM);
    power[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        power[i] = (power[i - 1] * (x % mod)) % mod;
    }
}
void initFactorial()
{
    fact.resize(NUM);
    fact[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
void calc_sieve()
{
    sieve.resize(NUM + 1, 0);
    for (int x = 2; x <= NUM; x++)
    {
        if (sieve[x])
            continue;
        for (int u = x; u <= NUM; u += x)
        {
            sieve[u] = x;
        }
    }
}
void primefactor()
{
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
 
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return ((a / gcd(a, b)) * b);
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    int64_t a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
 
    vector<int64_t> pref(n+1);
    
    pref[0] = 0;
    map<int64_t, vector<int>> app;
    app[0].pb(0);
    for (int i = 1;i <= n; i++) {
        pref[i] = pref[i-1] ^ a[i];
        app[pref[i]].pb(i);
    }
    
 
    int l, r;
    for (int o = 0; o < q; o++) {
        cin >> l >> r;
        int64_t n1 = pref[l-1];
        int64_t n2 = pref[r];
 
        int64_t res = 0;
        for (int i = 0; i < 64; i++) {
            int64_t b1 = (n1 >> i) & 1;
            int64_t b2 = (n2 >> i) & 1;
            if (b1 != b2) {
                res |= ((int64_t)1<<i);
            }
        }
        if (res == 0){
            cout << "YES\n";
            continue;
        } 
        int64_t look = pref[r];
        const vector<int>& vals = app[look];
        auto it = lower_bound(vals.begin(), vals.end(), l);

        if (it == vals.end() || *it > r) {
            cout << "NO\n";
            continue;
        }
        int idx = *it;
        const vector<int>& vals2 = app[pref[l-1]];
        auto it2 = lower_bound(vals2.begin(), vals2.end(), idx);
        if (it2 != vals2.end()) {
            int idx2 = *it2;
            if (idx2 <= r) {
                cout << "YES\n";
                continue;
            } else {
                cout << "NO\n";
                
            }
        } else {
            cout << "NO\n";
        }
    }
    cout << endl;
    
}
 
 
signed main() {
 ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
 
}