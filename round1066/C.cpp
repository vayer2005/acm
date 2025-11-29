#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    int c[q];
    int r[q];
    int l[q];

    vector<int> a(n+1, 1e9);
    vector<int> mn(n+1,0);
    vector<int> mx(n+1,0);

    for (int i = 0; i < q; i++) {
        cin >> c[i] >> l[i] >> r[i];
        for (int j = l; j <= r; j++) {
            if (c[j] == 1) {
                mn[j] = 1;
            } else {
                mx[j] = 1;
            }
        }
    }   

    for (int i = 0; i < q; i++) {
      
    }




}


signed main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    
    

}