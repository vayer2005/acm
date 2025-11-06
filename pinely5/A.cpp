#include <bits/stdc++.h>
 
 
#define int long long
 
using namespace std;
 
void solve() {
    int r0, x, d, n;
    cin >> r0 >> x >> d >> n;
 
    string s;
    cin >> s;
    int tot = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            tot++;
 
            if (x > r0) {
                r0 = min(r0+d, x-1);
            } else {
                r0 = max(r0-d, x-1);
            }
        } else {
            if (r0 < x) tot++;
        }
    }
 
    cout << tot << endl;
}
 
signed main() {
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
}