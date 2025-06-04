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
 
 
 
int vis[300001];
vector<pair<int, int>> adj[300001];
int k, d;
 
signed main()
{
    int n; cin >> n >> k >> d;
 
    for (int i = 0; i < 300001; i++) {
        vis[i] = 0;
    }
 
    queue<pair<int,int>> q;
    int v;
    for(int i = 0; i < k;i++) {
        cin >> v;
        q.push({v,0}); // val, parent
    }
 
 
    int x,y;
 
    for (int i= 0; i < n-1; i++) {
        cin >> x >> y;
        adj[x].push_back({y,i+1});
        adj[y].push_back({x,i+1});
    }
 
    set<int> shutdown;
 
    while (!q.empty()) {
        int pos = q.front().first;
        int from = q.front().second;

        q.pop();
        
        if(vis[pos]) continue;
        vis[pos] = 1;
 
        for (auto y : adj[pos]) {
            int x = y.first;
            if (x != from) {
                if (vis[x]) shutdown.insert(y.second);
                else q.push({x, pos});
            }
        }
 
    }
 
    cout << shutdown.size() << endl;
    for (int x : shutdown) {
        cout << x << " ";
    }
    cout << endl;
 
    
 
 
 
    
 
 
}