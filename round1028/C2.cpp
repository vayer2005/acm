#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
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
 
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
 
 

int n;
int arr[5001];
vector<int>u;
map<int, int> memo;
 

int dfs(int g, int val) {
    if (val == g) {
        return 0;
    }
    int mingcd = 1e9;

    if (memo.find(val) != memo.end()) {
        return memo[val];
    }

    for (int x : u) {
        int next = gcd(val, x);
        if (next < val) {
            mingcd = min(mingcd, dfs(g, gcd(val, x)));
        }

    }
    memo[val] = mingcd + 1;
    return mingcd+1;
}
 
 
void solve()
{
    u.clear();
    memo.clear();
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
 
    int g = 0;
    for (int i = 0; i<n; i++) {
        g = gcd(g, arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        u.push_back(arr[i]);    
    }   

    int res = 0;
    for (int i = 0; i<n; i++) {
        if (arr[i] == g) {
            res++;
        }
    }
    if (res>0) {
        cout << n - res << endl;
        return;
    }
    
 
    int ans = 1e9;
    for(int i = 0; i<u.size(); i++) {
        ans = min(ans, dfs(g, u[i]));
    }
    
    cout << ans + n-1 << endl;
}
 
    
 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    
    while (t--)
        solve();
    return 0;
}