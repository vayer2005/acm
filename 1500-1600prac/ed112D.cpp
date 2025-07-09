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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    string p1 = "";
    string p2 = "";
    string p3 = "";
    string p4 = "";
    string p5 = "";
    string p6 ="";
    for (int i = 0; i < n; i+=3) {
        p1 += "abc";
    }
    for (int i = 0; i < n; i+=3) {
        p2 += "acb";
    }
    for (int i = 0; i < n; i+=3) {
        p3 += "bac";
    }
    for (int i = 0; i < n; i+=3) {
        p4 += "bca";
    }
    for (int i = 0; i < n; i+=3) {
        p5 += "cab";
    }
    for (int i = 0; i < n; i+=3) {
        p6 += "cba";
    }

    p1=p1.substr(0,n); p2=p2.substr(0,n); 
    p3=p3.substr(0,n); p4=p4.substr(0,n); 
    p6=p6.substr(0,n); p5=p5.substr(0,n); 


    int pref1[n];
    int pref2[n];
    int pref3[n];
    int pref4[n];
    int pref5[n];
    int pref6[n];

    pref1[0] = (s[0] == p1[0]) ? 0 : 1;
    for (int i = 1; i < n; i++) {
        pref1[i] = pref1[i-1];
        pref1[i] += (s[i] == p1[i]) ? 0 : 1;
    }


    pref2[0] = (s[0] == p2[0]) ? 0 : 1;
    for (int i = 1; i < n; i++) {
        pref2[i] = pref2[i-1];
        pref2[i] += (s[i] == p2[i]) ? 0 : 1;
    }

    pref3[0] = (s[0] == p3[0]) ? 0 : 1;
    for (int i = 1; i < n; i++) {
        pref3[i] = pref3[i-1];
        pref3[i] += (s[i] == p3[i]) ? 0 : 1;
    }

    pref4[0] = (s[0] == p4[0]) ? 0 : 1;
    for (int i = 1; i < n; i++) {
        pref4[i] = pref4[i-1];
        pref4[i] += (s[i] == p4[i]) ? 0 : 1;
    }

    pref5[0] = (s[0] == p5[0]) ? 0 : 1;
    for (int i = 1; i < n; i++) {
        pref5[i] = pref5[i-1];
        pref5[i] += (s[i] == p5[i]) ? 0 : 1;
    }

    pref6[0] = (s[0] == p6[0]) ? 0 : 1;
    for (int i = 1; i < n; i++) {
        pref6[i] = pref6[i-1];
        pref6[i] += (s[i] == p6[i]) ? 0 : 1;
    }


    int l, r;

    while (q--) {
        cin >> l >> r;
        l--;r--;
        int minC;
        if (l == 0) {
            minC = min({pref1[r], pref2[r], pref3[r], pref4[r], pref5[r], pref6[r]});
        } else {
            minC = min({pref1[r] - pref1[l-1], pref2[r]-pref2[l-1], pref3[r]-pref3[l-1], pref4[r]-pref4[l-1], pref5[r]-pref5[l-1], pref6[r]-pref6[l-1]});
        }
        cout << minC << endl;
    }

    
}  

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}