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
    
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n%2==0) {
        for (int i = 0; i < n-1; i+=2) {
            bool z1 = false;
            bool z2 = false;

            if (a[i] < 0) {
                z1 = true;
                a[i] *= -1;
            } if (a[i+1] < 0) {
                z2 = true;
                a[i+1] *= -1;
            }
            int l = lcm(a[i], a[i+1]);
            int m1 = l/a[i];
            int m2 = l/a[i+1];

            if (z1) {
                cout << m1 << " ";
            } else {
                cout << -1 * m1 << " ";
            }
            if (z2) {
                cout << -1*m2  << " ";
            } else {
                cout << m2 << " ";
            }

        }
        cout << endl;
        return;
    } else {
        bool z1 = false;
        bool z2 = false;
        bool z3 = false;
        int curr = abs(a[0]) + abs(a[1]);
        if (a[2] < 0) {z3 = true; a[2] *= -1;}

        if (a[0] < 0) z1 = true;
        if (a[1] < 0) z2 = true;
        if (z1 && z2) { // both negative
            cout << -1 * a[2] << " " << -1 * a[2] << " ";
        } else if (z1 && !z2) {
            cout << -1 * a[2] << " " << a[2] << " ";
        } else if (!z1 && z2) {
            cout << a[2] << " " << -1*a[2] << " ";
        } else {
            cout << a[2] << " " << a[2] << " ";
        }

        if (z3) {
            cout << curr << " ";
        } else {
            cout << -1*curr << " ";
        }

        for (int i = 3; i < n-1; i+=2) {
            z1 = false;
            z2 = false;

            if (a[i] < 0) {
                z1 = true;
                a[i] *= -1;
            } if (a[i+1] < 0) {
                z2 = true;
                a[i+1] *= -1;
            }
            int l = lcm(a[i], a[i+1]);
            int m1 = l/a[i];
            int m2 = l/a[i+1];

            if (z1) {
                cout << m1 << " ";
            } else {
                cout << -1 * m1 << " ";
            }
            if (z2) {
                cout << -1*m2  << " ";
            } else {
                cout << m2 << " ";
            }

        }
        cout << endl;
        return;
    }
    
}  

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin >> t;
    while (t--) solve();
    return 0;
}