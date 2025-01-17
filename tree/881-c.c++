#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll total = 0;

    while (n >= 1) {
        total += n;
        n = floor(n/2);
    }
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}