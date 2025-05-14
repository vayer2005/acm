#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
using namespace std;
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
const int N = 10000000;
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


int maxSubarraySum(vector<int> &arr)
{
    if (!arr.size())
    {
        return 0;
    }
 
    int res = arr[0];
    int maxEnding = arr[0];
 
    for (int i = 1; i < arr.size(); i++)
    {
 
        // Find the maximum sum ending at index i by either extending
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
 
        // Update res if maximum subarray sum ending at index i > res
        res = max(res, maxEnding);
    }
    return max(res, 0ll);
}
 
void solve()
{
    ll n;
    cin >> n;
    vi v(n);
    cin >> v;
    ll vv = 0;
    ll ii = -1;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] != 1 && v[i] != -1)
        {
            vv = v[i];
            ii = i;
        }
    }
    set<ll> s, s1;
    s.insert(0);
    s1.insert(0);
    if (ii != -1)
    {
        ll sum = 0;
        for (ll i = ii + 1; i < n; i++)
        {
            sum += v[i];
            s.insert(sum);
        }
        sum = 0;
        for (ll i = ii - 1; i >= 0; i--)
        {
            sum += v[i];
            s1.insert(sum);
        }
        ll l = *(s.begin()) + *(s1.begin()), r = *(s.rbegin()) + *(s1.rbegin());
        ll a1 = l + v[ii];
        ll b1 = r + v[ii];
        vi v1, v2, v3, v4;
        for (ll i = 0; i < ii; i++)
        {
            v1.pb(v[i]);
            v2.pb(-v[i]);
        }
        for (ll i = ii + 1; i < n; i++)
        {
            v3.pb(v[i]);
            v4.pb(-v[i]);
        }
        ll b2 = maxSubarraySum(v1);
        ll a2 = -maxSubarraySum(v2);
        ll b3 = maxSubarraySum(v3);
        ll a3 = -maxSubarraySum(v4);
        set<ll> ans;
        for (ll i = a1; i <= b1; i++)
        {
            ans.insert(i);
        }
        for (ll i = a2; i <= b2; i++)
        {
            ans.insert(i);
        }
        for (ll i = a3; i <= b3; i++)
        {
            ans.insert(i);
        }
        ans.insert(0);
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        ll a = maxSubarraySum(v);
        for (auto &it : v)
        {
            it = -it;
        }
        ll b = -maxSubarraySum(v);
        cout << a - b + 1 << endl;
        for (ll i = b; i <= a; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}