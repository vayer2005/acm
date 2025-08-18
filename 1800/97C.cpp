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
const int mod = 1e9+7;
const int NUM = 1000030;
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
/*
Source: https://github.com/TimonKnigge/Competitive-Programming/blob/master/Kattis/tourist.cpp
*/

struct FlowNetwork {
	struct edge {
		int v, rev; int cap, cost, flo;
		edge (int _v, int _cap, int _cost) : v(_v),
			cap(_cap), cost(_cost), flo(0) { }
	};
	int V;
	vector< vector<edge> > e;
	FlowNetwork(int V) : V(V) {
		e.assign(V, vector<edge>());
	}
	void add_edge(int u, int v, int uv_cap, int uv_cost) {
		e[u].push_back(edge(v, uv_cap,  uv_cost));
		e[v].push_back(edge(u,      0, -uv_cost));
		e[u].back().rev = e[v].size() - 1;
		e[v].back().rev = e[u].size() - 1;
	}
	pair<int, int> mcmf(int s, int t);
};

vector<int> d;

typedef pair<int, int> li;
pair<int, int> FlowNetwork::mcmf(int s, int t) {
	int flow = 0, cost = 0;
	vector<pair<int, int> > p(V, {-1, -1});
	vector<int> pot(V, 0);
	d.assign(V, 9e18);
	d[s] = 0;
	
	// Set potentials
	bool ch = true;
	for (int it = 0; it < V - 1 && ch; ++it) {
		ch = false;
		for (int u = 0; u < V; ++u) {
			if (d[u] == 9e18) continue;
			for (int i = 0; i < (int)e[u].size(); ++i) {
				edge &uv = e[u][i];
				if (uv.cap == uv.flo) continue;
				int v = uv.v;
				if (d[v] == 9e18 || d[v] > d[u] + uv.cost) {
					d[v] = d[u] + uv.cost;
					ch = true;
				}
			}
		}
	}
	for (int i = 0; i < V; ++i)
		if (d[i] != 9e18) pot[i] = d[i];
	
	
	while (true) {
		d.assign(V, -1);
		d[s] = 0;
		auto comp_func = [&](int i, int j) {
			return (d[i] != d[j] ? d[i] < d[j] : i < j);
		};
		set<int, decltype(comp_func)> st(comp_func);
		st.insert(s);
		while (!st.empty()) {
			int u = *st.begin();
			st.erase(st.begin());
			for (int i = 0; i < (int)e[u].size(); ++i) {
				edge &uv = e[u][i];
				if (uv.cap == uv.flo) continue;
				int v = uv.v;
				int w = d[u] + uv.cost + pot[u] - pot[v];
				if (d[v] == -1 || w < d[v]) {
					if (st.find(v) != st.end())
						st.erase(st.find(v));
					d[v] = w;
					p[v] = {u, i};
					st.insert(v);
				}
			}
		}
		if (d[t] == -1) break;
		int u = t;
		int cap = 9e18;
		while (u != s) {
			edge &uv = e[p[u].first][p[u].second];
			cap = min(cap, uv.cap - uv.flo);
			u = p[u].first;
		}
		if (cap == 0) break;
		u = t;
		flow += cap;
		while (u != s) {
			edge &uv = e[p[u].first][p[u].second];
			edge &vu = e[uv.v][uv.rev];
			uv.flo += cap;
			vu.flo -= cap;
			cost += cap * uv.cost;
			u = p[u].first;
		}
		for (int i = 0; i < V; ++i)
			if (d[i] != -1) pot[i] += d[i];
	}
	
	return {flow, cost};
}


 
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
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int source = 0;
    int sink = 1 + n + 2*n; //tot nodes
    
    FlowNetwork flow(sink + 1);
    
    for (int i = 0; i < n; i++) {
        flow.add_edge(source, 1 + i, 1, 0);
    }
    
    for (int i = 0; i < n; i++) {
        for (int time = 1; time <= 2*n; time++) {
            int cost = abs(time - t[i]);
            flow.add_edge(1 + i, 1 + n + time - 1, 1, cost);
        }
    }
    
    for (int time = 1; time <= 2*n; time++) {
        flow.add_edge(1 + n + time - 1, sink, 1, 0);
    }
    
    auto [flow_val, cost] = flow.mcmf(source, sink);
    
    cout << cost << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
 
    while(t--) solve();
    
    return 0;
 
}