#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; 
    cin >> n;

    int count = 1;
    ll ans = 0;
    for (int i = n; i > 0; i--) {
        ans += abs(i-count);
        count += 1;
    }
    ans /= 2;
    ans += 1;
    cout << ans << endl;
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}