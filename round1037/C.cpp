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
    int n, k;
    cin >> n >> k;

    k--;
    int a[n];
    int maxH = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxH = max(maxH, a[i]);
    }

    if (a[k] == maxH) {
        cout << "YES\n";
        return;
    }

    int v = a[k];
    vector<int> rest;
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (a[i] > v) {
            rest.pb(a[i]);
        }
    }
    sort(rest.begin(), rest.end());
    int lee = v;

    int prev = v;

    for (int i = 0; i < rest.size(); i++) {
        if (rest[i] == prev) continue;
        int diff = rest[i] - prev;
        if (diff > lee) {
            cout << "NO\n";
            return;
        } if (rest[i] == maxH) {
            cout << "YES\n";
            return;
        } else {
            prev = rest[i];
        }
    }

    cout << "NO\n";

    
    
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