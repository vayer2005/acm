#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    double avg= 0;

    double curr;
    for (int i = 0; i < m; i++) {
        cin >> curr;
        avg += (curr+1.0)/2.0;
    }

    double bvg;

    for (int i = 0; i < n; i++) {
        cin >> curr;
        bvg += (curr + 1.0)/2.0;
    }

    if (avg == bvg) {
        cout << "TIED\n";
    } else if (avg > bvg) {
        cout << "ALICE\n";
    } else {
        cout << "BOB\n";
    }


}