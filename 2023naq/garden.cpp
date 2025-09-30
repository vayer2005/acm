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

double rr;
double r;
double w; double h;



double CalculatePartArea(double m, double n1, double n2)
        {   
            if (m < 0.01) return 0;

            double theta = atan(n1/m) + atan(n2/m);

            if (m >= r)
            {
                // case a
                return r * r * theta / 2;
            }

            double mm = m * m;

            if (n1 * n1 + mm >= rr)
            {
                if (n2 * n2 + mm >= rr)
                {
                    // case b
                    return rr * (theta - 2 * acos(m / r)) / 2
                           + m * sqrt(rr - mm);
                }

                // case d
                double d = sqrt(rr - mm) + n2;
                return d * m / 2
                        + rr * (theta - atan(n2/m) - acos(m / r)) / 2;
            }

            if (n2 * n2 + mm >= rr)
            {
                // case c
                double d = sqrt(rr - mm) + n1;
                return d * m / 2
                       + rr * (theta - atan(n1/m) - acos(m / r)) / 2;
            }

            // case e
            return m * (n1 + n2) / 2;
    }


void solve() {
    int n;
    cin >> n >> r >> w >> h;
    rr = r * r;

    int cx, cy, v; 
    double denom = w * h;
    double prot = 0;

    for (int i = 0; i < n; i++) {
        cin >> cx >> cy >> v;

        double area = CalculatePartArea(cy, cx, w - cx)
               + CalculatePartArea(cx, cy, h - cy)
               + CalculatePartArea(h - cy, cx, w - cx)
               + CalculatePartArea(w - cx, cy, h - cy);

        prot += (area/denom) * v;
        
    }

    cout << fixed << setprecision(14) << prot << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}