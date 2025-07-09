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


vector<int> dsu(1001,-1);
int spare = 0;

int findPar(int x) {
    int l = x;
    vector<int> path;
    while (dsu[l] > 0) {
        path.pb(l);
        l = dsu[l];
    }

    for (int y : path) {
        dsu[y] = l;
    }
    return l;
}

void merge(int x, int y) {
    int p1 = findPar(x);
    int p2 = findPar(y);
    if (p1 == p2) {
        spare++;
    } else {
        if (p1 < p2) swap(p1, p2);
        int tsize = dsu[p2];
        dsu[p2] = p1;
        dsu[p1] += tsize;
    }
}

void solve()
{   
    int n,m;cin >> n >> m;

    string s;
    cin >> s;

    string rl="";
    string ud="";
    for (char c : s) {
        if (c == 'L' || c == 'R') rl+=c;
        else ud+=c;
    }

    int minh = 0; int maxh = 0;
    int curr = 0;
    for (char c : rl) {
        if (c == 'R') {
            curr+= 1;
            maxh = max(maxh, curr);
        } else {
            curr-=1;
            minh = min(minh, curr);
        }

        if (maxh-minh >= m) {
            if (c == 'R') maxh-=1;
            else minh+=1;
            break;
        }
    }

    int finC = 0-minh;


    int minv = 0; int maxv = 0;
    curr = 0;
    for (char c : ud) {
        if (c == 'D') {
            curr+= 1;
            maxv = max(maxv, curr);
        } else {
            curr-=1;
            minv = min(minv, curr);
        }

        if (maxv-minv >= n) {
            if (c == 'D') maxv-=1;
            else minv+=1;
            break;
        }
    }

    int finR = 0-minv;

    cout << finR+1 << " " << finC+1 << endl;


    
    
}  

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin >> t;
    while (t--) solve();
    return 0;
}