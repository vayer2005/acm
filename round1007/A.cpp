#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    ll n;
    cin >> n;

    n-=1;
    if (n%3 == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

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