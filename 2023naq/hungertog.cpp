#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define int long long
#define double long double

using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int mod = 1e9+7;
const int NUM = 1e6+5; 
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
vector<int> lp, sieve;
vector<int> pr;
vi pow2(2e5+1, 0);
vector<int> power;
vector<int> fact(2e5 + 5, 0);
vector<int> inv_fact(2e5 + 5, 0);

int n, k;

vector<double> gain_per_day;
vector<int> expiry_of_day;

int works(double v) {
    double per_night = v * (double)k;

    priority_queue<pair<int, double>, vector<pair<int, double>>, greater<pair<int, double>>> pq;

    for (int i = 1; i <= n; i++) {
        if (gain_per_day[i] > 0) {
            pq.push({expiry_of_day[i], gain_per_day[i]});
        }

        double need = per_night;
        while (need > 1e-12 && !pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int expd = cur.first; double amt = cur.second;
            if (amt > need) {
                amt -= need;
                need = 0;
                if (amt > 1e-15) pq.push({expd, amt});
            } else {
                need -= amt;
            }
        }
        if (need > 1e-12) return 0;

        while (!pq.empty() && pq.top().first <= i) pq.pop();
    }
    return 1;
}

void solve() {
    
    cin >> n >> k;

    gain_per_day.assign(n + 2, 0);
    expiry_of_day.assign(n + 2, 0);

    int q, f;
    double total_q = 0;
    for (int i = 1; i <= n; i++) {
        cin >> q >> f;
        expiry_of_day[i] = f;
        gain_per_day[i] = (double)q;
        total_q += q;
    }

    double l = 0;
    double r = (k == 0 || n == 0) ? 0 : (double)(total_q) / ((double)k * (double)n);
    double best = 0;


    for (int it = 0; it < 80; it++) {
        double md = (l + r) / 2.0;
        if (works(md)) {
            if (md > best) best = md;
            l = md;
        } else {
            r = md;
        }
    }
    if (best <= 1e-12) {
        cout << "-1\n";
        return;
    }
    cout << fixed << setprecision(14) << best << endl;

    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}