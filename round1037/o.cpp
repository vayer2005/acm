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
// ---------------- Rainbow Bowls Problem ----------------

void solve() {
    long long n; int m;
    if(!(cin >> n >> m)) return; // no input
    vector<long long> gaps;
    gaps.reserve(m);
    for(int i=0;i<m;++i){
        long long c; cin >> c;
        if(c < n) gaps.push_back(n - c); // gap length
    }

    int k = (int)gaps.size();
    if(k == 0){
        cout << 1 << '\n';
        return;
    }

    sort(gaps.begin(), gaps.end(), greater<long long>());
    vector<long long> pref(k+1,0);
    for(int i=0;i<k;++i) pref[i+1] = pref[i] + gaps[i];

    int best = 1; // at least 1 rainbow range always possible when k>0
    for(int c=1;c<=k;++c){
        long long sumLargest = pref[c];
        if(n - sumLargest >= c){
            best = c; // larger c still feasible
        } else {
            break; // further c will only increase sumLargest, impossible
        }
    }

    cout << best << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}