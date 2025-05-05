#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int x; int y;
    cin >> x >> y;
    if (y == 1 || x == 1) {
        cout << 1 << endl;
        cout << x << " " << y << endl;
        return;
    }

    cout << 2 << endl;

    cout << 1 << " " << y-1 << endl;
    cout << x << " " << y << endl;
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