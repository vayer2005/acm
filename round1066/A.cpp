#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve() {
    int n;
    cin >> n;
    int a;
    map<int,int> occur;

    for (int i = 0; i < n; i++) {
        cin >> a;
        occur[a]++;
    }

    int ans = 0;
    for (auto &it : occur) {
        if (it.second >= it.first) {
            ans += it.second-it.first;
        } else {
            ans += it.second;
        }
    }

    cout << ans << endl;

}


signed main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    
    

}