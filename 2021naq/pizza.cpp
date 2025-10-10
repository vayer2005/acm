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
    int g = gcd(a, b);
    if (g == 0) return 0; // Avoid division by zero
    return ((a / g) * b);
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

struct Rational {
  int num, den;
};



Rational reduce(Rational in) {
  int g = gcd(in.num, in.den);
  in.num /= g;
  in.den /= g;
  return in;
}

int ans = 0;
int curr = 1;
void calc(int n, int mask, vi &arr) {
    vi used;
    for (int i = 0; i < n; i++) {
        if ((mask >> i)&1) {
            used.pb(arr[i]);
        }
    }

    int tot = 1;
    for (int i = 0; i < used.size(); i++) {
        tot *= used[i];
    }

    if (used.size() % 2 == 0) {
        ans -= curr/tot;
    } else {
        ans += curr/tot;
    }
}

void solve() {
    int c;
    cin >> c;

    map<string, int> andNode;
    map<string, int> orNode;
    vector<int> absNode;

    map<string, int> indeg;
    map<string, int> cnt;

    map<string, vector<string>> edges;
    queue<string> q;
    string s;
    getline(cin, s);

    for (int i = 0; i < c; i++) {
        getline(cin, s);

        if (s.size() > 2 && s.substr(0,3) == "if ") {
            stringstream ss(s);

            vector<string> v;

            while (getline(ss, s, ' ')) {
                v.push_back(s);
            }
            int m = v.size();
            string topr = v[m-1] + to_string(cnt[v[m-1]]);
            cnt[v[m-1]]++;
            if (m > 4) {
                if (v[2] == "or"){
                    //or case
                    orNode[topr] = 1;
                    for (int j = 1; j < m-1; j+=2) {
                        edges[v[j]].pb(topr);
                        indeg[topr]++;
                    }
                    
                } else {
                    //and case
                    andNode[topr] = 1;
                    for (int j = 1; j < m-1; j+=2) {
                        edges[v[j]].pb(topr);
                        indeg[topr]++;
                    }
                }
            } else {
                // single case(treat as and)
                andNode[topr] = 1;
                for (int j = 1; j < m-1; j+=2) {
                    edges[v[j]].pb(topr);
                    indeg[topr]++;
                }

            }
        } else {
            //absolute ingredient
            q.push(s);
        }
    }
    

    set<string> vis;
    int ans = 0;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (vis.find(curr) != vis.end()) continue;
        vis.insert(curr);
        //cout << curr << endl;
        //ans++;

        for (string x : edges[curr]) {
            if (orNode[x]) {
                //and case
                indeg[x]--;
                q.push(x.substr(0, x.size()-1));
            } else {
                //or case
                indeg[x]--;
                if (indeg[x] == 0) {
                    q.push(x.substr(0, x.size()-1));
                }
            }
        }
    }

    cout << vis.size() << endl;





}

    



 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}