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
 
 

int color[200001];
int vis[200001];
map<int,vector<int>> adj;


int dfs(int val) {
    vis[val] = 1;
    bool res = true;
    for (int x : adj[val]) {
        if (color[val] == color[x]) return false;
        if (vis[x] != 1) {
            color[x] = !color[val];
            res = res & dfs(x);
        }
    }
    return res;
}
 

 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;


    int from, to;
    vector<pair<int,int>> edges;
    for(int i = 0; i<m; i++ ){ 
        cin >> from >> to;
        edges.push_back({from,to});
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for(int i = 0; i < 200001; i++) {
        color[i] = -1;
    }

    color[1] = 0;
    if (!dfs(1)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    string sol = "";
    for (auto x : edges) {
        if (color[x.first] == 1) {
            sol += "0";
        } else {
            sol += "1";
        }
    }

    cout << sol << endl;

}