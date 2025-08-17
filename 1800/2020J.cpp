#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef long long ll;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int mod = 1e9+7;
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


struct DSU
{
	int S;
	
	struct node
	{
		int p; int sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	int getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> edges;
    ll u, v, w;
    ll mxweight = 0;
    ll mxsmaller = 0;
    ll closest = 1e18;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        mxweight = max(w, mxweight);
        if (w >= k) {closest = min(closest, w);}
        else mxsmaller = max(mxsmaller, w);
        edges.pb({w, u-1, v-1});
    }

    if (mxweight <= k) {
        cout << k - mxweight << endl;
        return;
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);

    ll nmerges = 0;
    ll finInd = m;
    for (ll i = 0; i < m; i++) {
        ll w = edges[i][0];
        ll u = edges[i][1];
        ll v = edges[i][2];
        if (w > k) {
            finInd = i;break;
        }
        if (!dsu.sameset(u, v)) {
            dsu.merge(u, v);
            nmerges++;
        }
    }
    ll ans = 0;
    if (nmerges == n-1) {
        cout << min(closest-k, k-mxsmaller) << endl;
        return;
    }

    while (finInd < m && nmerges < n-1) {
        ll w = edges[finInd][0];
        ll u = edges[finInd][1];
        ll v = edges[finInd][2];
        if (!dsu.sameset(u, v)) {
            ans += w-k;
            dsu.merge(u, v);
            nmerges++;
        }

        finInd++;
    }

    cout << ans << endl;



}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
 
    while(t--) solve();
    
    return 0;
 
}