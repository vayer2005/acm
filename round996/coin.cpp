#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll total = 1;

    while (n > 3) {
        n = floor(n/4);
        total *= 2;
    }
    cout <<  total << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}