#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
//#define int long long
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int mod = 1e9+7;
const int NUM = 300000;
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
// smallest prime factor table
vector<int> spf;

void init_spf() {
    spf.resize(NUM + 1);
    for (int i = 2; i <= NUM; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            if (1LL * i * i <= NUM)
                for (long long j = 1LL * i * i; j <= NUM; j += i)
                    if (spf[j] == 0) spf[j] = i;
        }
    }
}

vector<int> get_primes(int x) {
    vector<int> pf;
    while (x > 1) {
        int p = spf[x];
        pf.push_back(p);
        while (x % p == 0) x /= p;
    }
    return pf;
}
 
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
int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);
}
int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}
int C(int n, int k)
{
    if (k > n)
        return 0;
    int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
    int p2 = (1 * inversemod(fact[n - k], mod)) % mod;
    return (p1 * p2) % mod;
}


void solve() { 
    init_spf();
    int n;
    cin >> n;
    
    int a[n];

   vvi fact(NUM + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s, t;
    cin >> s >> t;
    s--;t--;
     
    for (int i = 0; i < n; i++) {
        auto pf = get_primes(a[i]);
        for (int p : pf) fact[p].pb(i);
    }
       
    
    vector<int> parent(n, -1);
    parent[s] = s;
    queue<int> q;
    q.push(s);

    bool found = false;

    while (!q.empty() && !found) {
        int i = q.front();
        q.pop();
        auto pf = get_primes(a[i]);
        for (int p : pf) {
            for (int y : fact[p]) {
                if (parent[y] == -1) {
                    parent[y] = i;
                    if (y == t) {
                        found = true;
                        break;
                    }
                    q.push(y);
                }
            }
            vector<int>().swap(fact[p]);
            if (found) break;
        }
    }

    if (parent[t] == -1) {
        cout << "-1\n";
        return;
    }

    vector<int> ord;
    int sr = t;
    while (sr != s) {
        ord.pb(sr + 1);
        sr = parent[sr];
    }
    ord.pb(s + 1);
    reverse(ord.begin(), ord.end());
    cout << ord.size() << endl;
    for (int x : ord) {
        cout << x << " ";
    }
    cout << endl;

    


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}