#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int w, s;
    cin >> w >> s;

    int c = (s+1) * s / 2;
    int allt = 29260 * c;

    int gold = (w - allt)/110;

    cout << gold << endl;
}

signed main() {
  solve();
}