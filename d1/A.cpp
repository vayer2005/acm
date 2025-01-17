#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



void solve() {
    int n; int m;
    cin >> n >> m;
    int bottomx = 0; int bottomy = 0;
    int topx = m; int topy = m;
    int x; int y;
    cin >> x >> y;

    bottomx += x; bottomy += y;
    topx += x; topy += y;

    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        topx += x;
        topy += y;
    } 

    ll res = 2 * (topx - bottomx) + 2 * (topy - bottomy);
    cout << res << endl;

}



int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}