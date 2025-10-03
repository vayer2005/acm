#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define int long long

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
const int N = 1e7+1;
const double EPS = 1e-7;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
vector<int> lp, sieve;
vector<int> pr;
vi pow2(2e5+1, 0);
vector<int> power;
vector<int> fact(2e5 + 5, 0);
vector<int> inv_fact(2e5 + 5, 0);

vi primes(10000001, 0);
vi prefix(10000001, 0);
vector<int> primes2(10000001, 0);

void solve(int t) {
    int n; 
    cin >> n;
    cout << "Case #" << t+1 << ": " << prefix[n]<< endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
   
    

    vector<int> p, ip(N, 1);
    for (int i = 2; i < N; ++i) {
        if (!ip[i]) continue;
        primes[i] = 1;
        for (int j = i; j < N; j += i) {
           ip[j] = 0;
        }
    }

    primes2[5] = 1;
    for (int i = 5; i < N; i++) {
        if (primes[i] && primes[i-2]) {
            primes2[i]++;
        }
    }

    prefix[0] = primes2[0];
    for (int i = 1; i < N+1; i++) {
        prefix[i] = prefix[i-1] + primes2[i];
    }
 

    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }



    
    
    return 0;
}