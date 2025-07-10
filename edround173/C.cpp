#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 2e5+5;

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
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mn1=0;
    int mx1=0;
    int curr = 0;
    int ind = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 1 && a[i] != -1) {
            ind = i;
            break;
        }
        curr += a[i];
        if (curr < 0) curr = 0;
        mx1 = max(mx1, curr);
    }

    curr = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 1 && a[i] != -1) {
            break;
        }
        curr += a[i];
        if (curr > 0) curr = 0;
        mn1 = min(mn1, curr);
    }

    int mn2=0;
    int mx2 = 0;
    curr = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] != 1 && a[i] != -1) {
            break;
        }
        curr += a[i];
        if (curr < 0) curr = 0;
        mx2 = max(mx2, curr);
    }

    curr = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] != 1 && a[i] != -1) {
            break;
        }
        curr += a[i];
        if (curr > 0) curr = 0;
        mn2 = min(mn2, curr);
    }

    if (ind == -1) {
        cout << mx1-mn1+1 << endl;
        for (int i = mn1; i <= mx1; i++) {
            cout << i << " ";
        }
        cout << endl;return;
    }

    int pref[n+1];
    pref[ind] = 0;
    int mnpref = 0;
    int mxpref = 0;
    for (int i = ind+1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i];
        mnpref = min(mnpref, pref[i]);
        mxpref = max(mxpref, pref[i]);
    }

    int suff[n+1];
    suff[ind] = 0;
    int mnsuff = 0;
    int mxsuff = 0;
    for (int i = ind-1;i>=1;i--) {
        suff[i] = suff[i+1] + a[i];
        mnsuff = min(mnsuff, suff[i]);
        mxsuff = max(mxsuff, suff[i]);
    }

    set<int> res;

    int mntot = mnsuff + mnpref + a[ind];
    int mxtot = mxsuff + mxpref + a[ind];
    for (int i = mntot; i <= mxtot; i++) {
        res.insert(i);
    }
    for (int i = mn1; i <= mx1; i++) {
        res.insert(i);
    }
    for (int i = mn2; i <= mx2; i++) {
        res.insert(i);
    }

    cout << res.size() << endl;
    while (!res.empty()) {
        int v = *res.begin();
        cout << v << " ";
        res.erase(v);
    }
    cout << endl;

}  

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {solve();}
    return 0;
}