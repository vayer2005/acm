#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string x;
    cin >> x;
    int i = 0;

    while (i < x.size()) {
        cout << "H";
        if (x.substr(i,2) == "33") {
            x = x.substr(0,i) + x.substr(i+2,x.size() - i);
        }
        i += 1;
    }

    ll num = itos(x);

    if (num % 33 == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}