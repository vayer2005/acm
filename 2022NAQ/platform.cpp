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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s, k;
    cin >> n >> s >> k;

    vi x(n+2,0);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    x[n] = -1e10;
    x[n+1] = 1e10;

    sort(x.begin(), x.end());

    vi y(n+2,s);
    y[0] = 0;
    y[n+1] = 0;

    for(int i = 1; i < n+1; i++) {

        int ybound1 = 2 * (x[i+1]-x[i])-y[i+1];
        int ybound2 = 2 * (x[i]-x[i-1])-y[i-1];
        if (ybound1 >= s && ybound2 >= s) {
            y[i] = min(ybound1, ybound2);
            y[i] = min(y[i], k);
        } else {
            cout << "-1\n";
            return 0;
        }
    }

    int sum=0;
    for(int i =0;i < n + 2;i++) {
        sum+=y[i];
    }
    cout << sum << endl;
    
}   