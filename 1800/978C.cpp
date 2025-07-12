#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
//#define int long long
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
 
 
 
void solve()
{   
    int n;
    cin >> n;
    char grid[n][2];
    string s1, s2;
    cin >> s1; cin >> s2;
    for (int i = 0; i < n; i++) {
        grid[i][0] = s1[i];
        grid[i][1] = s2[i];
    }

    const int NEG = -1000000000;
    int dp[n + 1][3];
    for (int i = 0; i <= n; ++i)
        for (int s = 0; s < 3; ++s)
            dp[i][s] = NEG;          

    dp[n][0] = dp[n][1] = dp[n][2] = 0;   
    dp[n-1][0] = dp[n-1][1] = dp[n-1][2] = 0;
    dp[n-2][0] = dp[n-2][1] = dp[n-2][2] = 0;
    

    for (int i = n-3; i >= 0; i--) {
        int p1 = 0;

        p1 += (grid[i+1][0] == 'A') ? 1 : 0;
        p1 += (grid[i+1][1] == 'A') ? 1 : 0;
        p1 += (grid[i+2][0] == 'A') ? 1 : 0;
        p1 /=2;

        dp[i][0] = max(dp[i][0], p1 + dp[i+1][1]);

        int p2 = 0;
        p2 += (grid[i+1][0] == 'A') ? 1 : 0;
        p2 += (grid[i+1][1] == 'A') ? 1 : 0;
        p2 += (grid[i+2][1] == 'A') ? 1 : 0;
        p2 /=2;
        
        dp[i][0] = max(dp[i][0], p2 + dp[i+1][2]);
        if (i < n-3) {
            int p3 = 0;
            p3 += (grid[i+1][0] == 'A') ? 1 : 0;
            p3 += (grid[i+2][0] == 'A') ? 1 : 0;
            p3 += (grid[i+3][0] == 'A') ? 1 : 0;
            p3 /=2;
            int p4 = 0;
            p4 += (grid[i+1][1] == 'A') ? 1 : 0;
            p4 += (grid[i+2][1] == 'A') ? 1 : 0;
            p4 += (grid[i+3][1] == 'A') ? 1 : 0;
            p4 /=2;
            int htot = p4 + p3;
            dp[i][0] = max(dp[i][0], htot + dp[i+3][0]);
        }

        // pos 1
        int p5 = 0;
        p5 += (grid[i+1][1] == 'A') ? 1 : 0;
        p5 += (grid[i+2][0] == 'A') ? 1 : 0; 
        p5 += (grid[i+2][1] == 'A') ? 1 : 0;
        p5 /=2;

        dp[i][1] = max(dp[i][1], p5 + dp[i+2][0]);
        if (i < n-4) {
            int p6 = 0;
            p6 += (grid[i+2][0] == 'A') ? 1 : 0;
            p6 += (grid[i+3][0] == 'A') ? 1 : 0;
            p6 += (grid[i+4][0] == 'A') ? 1 : 0;
            p6/=2;
            int px=0;
            px += (grid[i+1][1] == 'A') ? 1 : 0;
            px += (grid[i+2][1] == 'A') ? 1 : 0;
            px += (grid[i+3][1] == 'A') ? 1 : 0;
            px /=2;
            dp[i][1] = max(dp[i][1], p6+px + dp[i+3][1]);

        }

        // pos 2
        int p7 = 0;
        p7 += (grid[i+1][0] == 'A') ? 1 : 0;
        p7 += (grid[i+2][0] == 'A') ? 1 : 0;
        p7 += (grid[i+2][1] == 'A') ? 1 : 0;
        p7 /=2;
  
        dp[i][2] = max(dp[i][2], p7 + dp[i+2][0]);

        if (i < n-4) {
            int p8 = 0;
            p8 += (grid[i+1][0] == 'A') ? 1 : 0;
            p8 += (grid[i+2][0] == 'A') ? 1 : 0;
            p8 += (grid[i+3][0] == 'A') ? 1 : 0;
            p8/=2;
            int p9 = 0;
            p9 += (grid[i+2][1] == 'A') ? 1 : 0;
            p9 += (grid[i+3][1] == 'A') ? 1 : 0;
            p9 += (grid[i+4][1] == 'A') ? 1 : 0;
            p9 /=2;
            
            dp[i][2] = max(dp[i][2], p8+p9+dp[i+3][2]);

        }
    }
    // try all first options;
    int f1 = 0;
    f1 += (grid[0][0] == 'A') ? 1 : 0;
    f1 += (grid[0][1] == 'A') ? 1 : 0;
    f1 += (grid[1][0] == 'A') ? 1 : 0;
    f1/=2;
    //cout << dp[5][0] << endl;
    int ans = f1 + dp[0][1];
    //cout << "ans: " << ans << endl;
    int f2 = 0;
    f2 += (grid[0][0] == 'A') ? 1 : 0;
    f2 += (grid[0][1] == 'A') ? 1 : 0;
    f2 += (grid[1][1] == 'A') ? 1 : 0;
    f2/=2;
    ans = max(ans, f2 + dp[0][2]);
    int f3 = 0; int f4 = 0;
    f3 += (grid[0][0] == 'A') ? 1 : 0;
    f3 += (grid[1][0] == 'A') ? 1 : 0;
    f3 += (grid[2][0] == 'A') ? 1 : 0;
    f3 /=2;
    f4 += (grid[0][1] == 'A') ? 1 : 0;
    f4 += (grid[1][1] == 'A') ? 1 : 0;
    f4 += (grid[2][1] == 'A') ? 1 : 0;
    f4/=2;
    ans = max(ans, f3 + f4 + dp[2][0]);

    //cout << "i = 0: " << dp[0][2] << endl;
    cout << ans << endl;

}  
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}