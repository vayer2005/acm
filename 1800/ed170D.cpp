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
 
 
 
void solve()
{   
    int n, m;
    cin >> n >> m;
 
    int a[n];
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
 
    int dp[m+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    vector<int> v1; vector<int> v2;
    int seen = 0;
    for (int i = 0; i<n; i++) {
        if (a[i] == 0) {
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            for (int j = 0; j <= seen; j++) {
                int ind1 = upper_bound(v1.begin(), v1.end(), j) - v1.begin();
                int ind2 = upper_bound(v2.begin(), v2.end(), seen-j) - v2.begin();
                dp[seen][j] = ind1 + ind2;
                if (seen > 0) {
                    int comp = 0;
                    if (j > 0) comp = dp[seen-1][j-1];
                    dp[seen][j] += max(comp, dp[seen-1][j]);
                }
            }
            v1.clear();
            v2.clear();
            seen+=1;
        } else if (a[i] < 0) {
            v1.pb(-1 * a[i]);
        } else {
            v2.pb(a[i]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int j = 0; j <= seen; j++) {
        int ind1 = upper_bound(v1.begin(), v1.end(), j) - v1.begin();
        int ind2 = upper_bound(v2.begin(), v2.end(), seen-j) - v2.begin();
        dp[seen][j] = ind1 + ind2;
        if (seen > 0) {
            int comp = 0;
            if (j > 0) comp = dp[seen-1][j-1];
            dp[seen][j] += max(comp, dp[seen-1][j]);
        }
    }
    seen+=1;
    int sol = 0;
    for (int i = 0; i <= m; i++) {
        sol = max(sol, dp[m][i]);
    }

    cout << sol << endl;
 
 
}  
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
    return 0;
}