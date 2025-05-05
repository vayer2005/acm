#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int x; int y;
    cin >> x >> y;
    if (y == x+1) {
        cout << "YES\n";
        return;
    }
    else {
        while (x >= 0) {
            x -= 9;
            if (x + 1 == y) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }

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