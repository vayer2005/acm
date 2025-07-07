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
map<int,int> pval;
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
    int x;
    vector<int> cnt(2750132,0);
    for (int i = 0; i < 2*n; i++) {
        cin >> x;
        cnt[x]++;
    }

    vector<int> a;

    for (int i = 2750131; i>=1; i--) {
        while (cnt[i] > 0) {
            if (sieve[i] == 0) {
                //largest is prime
                a.pb(pval[i]);
                cnt[pval[i]]--;
                cnt[i]--;
            } else {
                //cout << i << " " << sieve[i] << endl;
                int vr = sieve[i];
                a.pb(i);
                cnt[vr]--;
                cnt[i]--;
            }
        }
    }

    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;


}  

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve.resize(2750132);
    fill(sieve.begin(), sieve.end(), 0);

    sieve[0] = 1; sieve[1]=1;
    int indc = 1;
    for (int i = 2; i <= 2750131; i++) {
        if (sieve[i] == 0) {
            pval[i] = indc;
            indc++;
        } 
        for (int j = i + i; j <= 2750131; j+=i) {
            sieve[j] = i;
        }
    }
    
    solve();
    return 0;
}