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

#define DEBUG(x) cerr << #x << ": " << x << '\n'
template <typename T, typename Y>
istream &operator>>(istream &is, pair<T, Y> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename Y>
ostream &operator<<(ostream &os, pair<T, Y> p)
{
    os << p.first << ' ' << p.second << ' ';
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
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

vector<vector<int>> adj[1001];
vector<vector<int>> edges;



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m,L,s,t, u, v, c;

    cin >> n >> m >> L >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;

        adj[u].pb({v,c,i});
        adj[v].pb({u,c,i});
        edges.pb({u,v,c});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    vector<int> dist(1001, INT_MAX);
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x[0];
            int weight = x[1];

            if (weight != 0 && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] < L) {
        cout << "NO\n";
        return 0;
    }

    
    vector<int> toChange;
    vector<int> dist2(1001, INT_MAX);
    pq.push({0,s});
    dist2[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x[0];
            int weight = x[1];
            int edgeNum = x[2];

            if (dist2[v] > dist2[u] + weight) {
                if (weight == 0) {
                    toChange.pb(edgeNum);
                }
                dist2[v] = dist2[u] + weight;
                pq.push({dist2[v], v});
            }
        }
    }

    //cout << dist2[t] << " " << toChange.size() << endl;
    if (toChange.size() + dist2[t] > L) {
        cout << "NO\n";
        return 0;
    }

    if (toChange.size() == 0 && dist2[t] != L) {
        cout << "NO\n";
        return 0;
    }

    int needed = L - dist2[t];
    int first = needed - (toChange.size()-1);
    //cout << first << endl;
    edges[toChange[0]][2] = first;
    for (int i = 1; i < toChange.size(); i++) {
        edges[toChange[i]][2] = 1;
    }

    cout << "YES\n";
    for(auto x : edges) {
        if (x[2] == 0) {
            cout << x[0] << " " << x[1] << " " << 1;
        } else {
            cout << x[0] << " " << x[1] << " " << x[2]; 
        }
        cout << endl;
    }



    



}