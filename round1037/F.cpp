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

int a[200001];
map<int, pair<int,int>> parent; // node to its parent and edge weight;
vector<pair<int,int>> adj[200001];
map<int, map<int,int>> colors;
int ans;

void dfs(int v, int p) {

    for (auto x : adj[v]) {
        int node = x.first;
        int weight = x.second;

        if (node != p) {
            parent[node] = {v, weight};
            int c =  a[node];
            colors[v][c] += weight;
            if (c != a[v]) ans += weight;
            dfs(node, v);
        }
    }
    //cout << v << " " << ans << endl;
}

void solve() {
    int n, q;
    cin >> n >> q;
    ans = 0;
    for (int i = 0; i < 200001; i++) {
        adj[i].clear();
        
    }
    colors.clear();
    parent.clear();
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int u, v, c;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> c;
        adj[u].pb({v,c});
        adj[v].pb({u,c});
    }

    dfs(1, 0);

    //cout << a[1] << " "<< a[2] << " " << a[3] << " " << a[4] << endl;
    while (q--) {
        cin >> v >> c;

        if (a[v] == c) {
            cout << ans << endl;
            continue;
        }

        int curr=a[v]; //current color

        ans += colors[v][curr];
        ans -= colors[v][c];

        int p = parent[v].first;
        int pcol = a[p];
        int weight = parent[v].second;

        if (pcol == curr) ans += weight;
        else if (pcol == c) ans -= weight;
        
        colors[p][curr] -= weight;
        colors[p][c] += weight;

        a[v] = c;

        cout << ans << endl;
    }


    
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