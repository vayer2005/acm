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
 
 

int cats[100001];
map<int,vector<int>> adj;
int k;

int dfs(int val, int consec, int par) {
    if (cats[val] == 1)
        consec++;
    else
        consec = 0;

    if (consec > k)
        return 0;

    int cnt = 0;
    int sol = 0;
    for (int x : adj[val]) {
        if (x != par) {
            cnt++;
            sol += dfs(x, consec, val);
        }
    }

    if (cnt == 0) return 1; 

    return sol;
}
 

 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    int from, to;
    for(int i = 0; i<n-1; i++ ){ 
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    cout << dfs(1,0, -1) << endl;



}