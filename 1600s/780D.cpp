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
const int INF = 1e9 + 13;
 
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
    int n;cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int last0 = -1;
    vi temp;
    map<int, vector<int>> wek;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            wek[last0] = temp;
            temp.clear();
            last0 = i;
        } else {
            temp.pb(a[i]);
        }
    }
    wek[last0] = temp;
    int best = 0;
    int bl = n; int br = 0;
    
    for (auto &it : wek) {
        
        vector<int> curr = it.second;
        int neg = 0;
        int prod = 1;
        for (int x : curr) {
            if (x < 0) neg++;
            prod += (abs(x) == 2);
        }

        if (neg%2 == 0) {
            if (prod > best) {
                best = prod;
                bl = it.first + 1;
                br = n - (it.first + 1 + curr.size());
            }
        } else {
            int leftin;
            int rightin;
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] < 0) {
                    leftin = i+1;
                    break;
                }
            }
            for (int i = curr.size()-1; i >= 0; i--) {
                if (curr[i] < 0) {
                    rightin = i-1;
                    break;
                }
            }
            int prod1 = 1;
            for (int i = leftin; i < curr.size(); i++) {
                prod1 += (abs(curr[i]) == 2);
            }
            if (prod1 > best) {
                best = prod1;
                bl = it.first + leftin+1;
                br = n - (it.first + curr.size()+1);
            }
            int prod2 = 1;
            for (int i = rightin; i >= 0; i--) {
                prod2 += (abs(curr[i]) == 2);
            }  
            if (prod2 > best) {
                best = prod2;
                bl = it.first + 1;
                int extra = curr.size() - rightin-1;
                br = n - (it.first + curr.size()+1) + extra;
            }
        }
    }

    cout << bl << " " << br << endl;




}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;

}