#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; int a; int b;

    cin >> n >> a >> b;

    if (abs(a-b) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}