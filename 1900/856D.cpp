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
const int NUM = 1e6+5; 
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
vector<int> lp, sieve;
vector<int> pr;
vector<int> power;
vector<int> fact(2e5 + 5, 0);
vector<int> inv_fact(2e5 + 5, 0);
vector<bool> is_prime(1000001, true);

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int binpow(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

 int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);
}

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
    
    // Precompute inverse factorials
    inv_fact.resize(NUM);
    for (int i = 0; i < NUM; i++) {
        inv_fact[i] = inversemod(fact[i], mod);
    }
}

void sieve_primes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 1000001; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * i; j < 1000001; j += i) {
            is_prime[j] = false;
        }
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

int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}


void solve() {
    int n;
    cin >> n;

    map<int, int> cnt;
    int cprod = 1;
    for (int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (auto [k, v] : cnt) {
        if (!is_prime[k]) {
            cprod = (cprod * inv_fact[v]) % mod;
            continue;
        }
        
        vector<int> new_dp = dp;
        for (int i = 0; i <= n; i++) {
            new_dp[i] = (dp[i] * inv_fact[v]) % mod;
        }
        for (int i = 1; i <= n; i++) {
            new_dp[i] = (new_dp[i] + (dp[i - 1] * inv_fact[v-1]) % mod) % mod;
        }
        dp = new_dp;
    }

    int ans = (dp[n] * fact[n]) % mod;
    ans = (ans * cprod) % mod;


    cout << ans << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve_primes();
    initFactorial();
    solve();
    
    return 0;
}