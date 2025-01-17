#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll a; ll b; ll c; ll n;
    cin >> n >> a >> b >> c;
    
    ll div = a + b + c;

    ll maxDays = 3 * ceil((n*1.0)/div);
    ll total = ceil((n*1.0)/div) * div;
    if (total - c - b >= n) {
        maxDays -= 2;
    } else if (total - c >= n) {
        maxDays -= 1;
    }
    cout << maxDays << endl;

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}