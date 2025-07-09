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

    set<int> seen;
    set<int> nog;
    int b[n+1];

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (seen.find(a[i]) != seen.end()) {
            nog.insert(i);
        } else {
            seen.insert(a[i]);
            b[i] = a[i];
            tot++;
        }
    }

    set<int> nin;
    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            nin.insert(i);
        }
    }

    cout << tot << endl;
    if (nin.size() == 0) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }


    while (nog.size() > 0 || nin.size() > 0) {
        if (nin.size() == 1 && *nin.begin() == *nog.begin()) {
            int curr = *nin.begin();
            for (int i = 1; i <= n; i++) {
                if (nog.find(i) == nog.end() && a[curr]==b[i]) {
                    int dest = b[i];    
                    b[i] = curr;
                    b[curr] = dest;
                    break;
                }
            }
            for (int i  =1; i <= n; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
            return;
        }
        
        int currNog = *nog.begin();
        bool matched = false;

        vector<int> add;
        while (!matched) {
            int currNin = *nin.begin();
            nin.erase(currNin);
            if (currNin != currNog) {
                b[currNog] = currNin;
                matched = true;
                nog.erase(currNog);
            } else {
                add.pb(currNin);
            }
        }
        for (int x : add) {
            nin.insert(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << b[i] << " "; 
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