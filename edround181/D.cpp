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

int mul(int x, int y) {
    return x * 1LL * y % mod;
}

 
int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int divide(int x, int y) {
  return mul(x, binpow(y, mod - 2));
}

int n, m;
vpi points;
vpi probs;

int l, r, p, q;
map<int, vector<int>> starts;
int total = 1;
 
int dp[200001];

int dfs(int idx) {
    if (idx == m+1) return 1;
    else if (idx > m+1) return 0;
    if (dp[idx] != -1) return dp[idx];

    int res = 0;
    for (int x : starts[idx]) {
        //cout << points[x].first << " " << points[x].second << endl;
        int num = probs[x].first;
        int den = probs[x].second;
        int curr = divide(num, den-num);

        curr *= (dfs(points[x].second + 1) % mod);
        curr %= mod;
        res += curr;
        res %= mod;
    } 
    dp[idx] = res;
    return res;

}


void solve() {

    cin >> n >> m;

    for (int i = 0; i<n; i++) {
        cin >> l >> r >> p >> q;
        points.pb({l,r});
        probs.pb({p,q});
        starts[l].pb(i);
        total = (total * divide(q-p,q)) % mod;
    }
    memset(dp, -1, sizeof(dp));
    dfs(1);
    cout << (dp[1] * total) % mod << endl;
    
    
  
}

signed main() {
 ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;

}