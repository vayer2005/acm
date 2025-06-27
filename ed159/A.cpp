#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int z = 0;
    for (char x : s) {
        if (x == '0') z++;
    }

    if (z > 0) {
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