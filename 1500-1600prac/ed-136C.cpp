#include <bits/stdc++.h>
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
const int mod = 1e9+7;
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


unsigned long long nCr(int n, int r) {
    if (r > n - r) r = n - r;
    unsigned long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i;
    }
    return res;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;

    cin >> t;
    unsigned long long dp[61][2];
    dp[2][0] = 1;
    dp[2][1] = 0;
    for (int i = 4; i <= 60; i+=2) {
        dp[i][0] = ((nCr(i-1, (i/2)-1)) + dp[i-2][1]);
        dp[i][1] = (nCr(i,i/2)- dp[i][0] - 1);
    }
        
    int v;
    while (t--) {
        cin >> v;
        cout << dp[v][0]%998244353 << " " << dp[v][1]%998244353 << " 1\n";
    }
        
    return 0;
}