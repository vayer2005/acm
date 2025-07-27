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
    int n, m, k;
    cin >> n >> m >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }

    vector<int> f(k);
    for (int i = 0; i < k; i++) {
        cin >> f[i];
    }

    int biggest = 0;
    int second = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] >= biggest) {
            second = biggest;
            biggest = a[i] - a[i-1];
        } else if (a[i] - a[i-1] >= second) {
            second = a[i] - a[i-1];
        }
    }
    sort(f.begin(), f.end());
    sort(d.begin(), d.end());

    if (biggest == second) {
        cout << biggest << endl;
        return;
    }

    int ind = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] == biggest) {
            ind = i;
        }
    }
    int needed = ((a[ind] - a[ind-1])/2) + a[ind-1];
    int mn = second;
    int m2 = biggest;

    for (int x : d) {
        int search = needed - x;
        auto it1 = lower_bound(f.begin(), f.end(), search);

        int i1;
        if (it1 == f.end()) {
            i1 = k - 1;
        } else {
            i1 = (it1 - f.begin());
        }
        int vl = f[i1] + x;
        if (vl > a[ind - 1] && vl < a[ind]) {
            m2 = min(m2, max(vl - a[ind - 1], a[ind] - vl));
        }

        if (i1 > 0) {
            vl = f[i1 - 1] + x;
            if (vl > a[ind - 1] && vl < a[ind]) {
                m2 = min(m2, max(vl - a[ind - 1], a[ind] - vl));
            }
        }

        if (i1 < k - 1) {
            vl = f[i1 + 1] + x;
            if (vl > a[ind - 1] && vl < a[ind]) {
                m2 = min(m2, max(vl - a[ind - 1], a[ind] - vl));
            }
        }
    

    }

    cout << max(mn, m2) << endl;



    
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