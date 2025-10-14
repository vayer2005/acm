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

vector<string> grid;
int r, c, s;
vvi vis;
map<pi, int> seen;


int dfs(int si, int sj) {
    if (si < 0 || si >= r || sj < 0 || sj >= c) return 0;
    if (vis[si][sj] == 1) return 0;
    if (grid[si][sj] != '.') return 0;

    int componentSize = 0;
    vector<pair<int,int>> stackCells;
    stackCells.push_back({si, sj});
    vis[si][sj] = 1;

    while (!stackCells.empty()) {
        auto [i, j] = stackCells.back();
        stackCells.pop_back();
        componentSize++;

        const int di[4] = {1, 0, -1, 0};
        const int dj[4] = {0, 1, 0, -1};
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
            if (vis[ni][nj] == 1) continue;
            if (grid[ni][nj] != '.') continue;
            vis[ni][nj] = 1;
            stackCells.push_back({ni, nj});
        }
    }

    return componentSize;
}

void solve(int t) {
    
    cin >> r >> c >> s;
    vis.assign(r, vi(c, 0));
    string row;
    grid.clear();
    seen.clear();
    queue<vi> q; 


    for (int i = 0; i < r; i++) {
        cin >> row;
        grid.pb(row);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '#') {
                q.push({0, i, j});
            }
        }
    }

    for (int i = 0; i < r; i++) {
        q.push({1, i, 0});
        q.push({1, i, c-1});
    }

    for (int i = 0; i < c; i++) {
        q.push({1, 0, i});
        q.push({1, r-1, i});
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int i = curr[1]; int j = curr[2];
        if (i < 0 || i >=r || j < 0 || j >= c) continue;
        int used = curr[0];
        if (seen[{i,j}] != 0) continue;
        grid[i][j] = '#';
        seen[{i,j}] = 1;
        if (used < s) {
            q.push({used+1, i+1, j});
            q.push({used+1, i, j+1});
            q.push({used+1, i-1, j});
            q.push({used+1, i, j-1});
        }
    }

    int mx = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '.') {
                mx = max(mx, dfs(i,j));
            }
        }
    }

    cout << "Case #" << t+1 << ": " << mx << endl; 


    


}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("B3.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve(i);
    
    return 0;
 
}