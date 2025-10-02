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



void solve() {
    int n; string s;
    cin >> n >> s;

    vi aind;
    vi bind;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            aind.pb(i);
        } else {
            bind.pb(i);
        }
    }

    int mida = aind.size()/2;
    int midb = bind.size()/2;

    int bans = 0;
    int aans = 0;
  

    int breach;

    if (bind.size() > 0) {
        if (midb > 0) {
        breach = bind[midb] - 1;
        for (int i = midb-1; i >= 0; i--) {
            bans += breach - bind[i];
            breach--;
        } 
    }
    
    if (midb < bind.size()-1) {
        breach = bind[midb] + 1;
        for (int i = midb + 1; i < bind.size(); i++) {
            bans += bind[i] - breach;
            breach++;
        }
    }
    

    }
    

    if (aind.size() > 0) {
        int areach;
    //cout << mida << endl;
    
    if (mida > 0) {
        //cout << "H";
        areach = aind[mida] - 1;
        for (int i = mida-1; i >= 0; i--) {
            aans += areach - aind[i];
            areach--;
        } 
    }
    
    //cout << mida << " " << aind.size() << endl;
        
    if (mida < aind.size()-1) {
        //cout << "H";
        areach = aind[mida] + 1;
        for (int i = mida + 1; i < aind.size(); i++) {
            aans += aind[i] - areach;
            areach++;
        }
    }


    }
    
    cout << min(aans, bans) << endl;
    

    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}