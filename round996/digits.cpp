#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



void solve() {
    int n; int d;
    cin >> n >> d;

    cout << "1 ";
    if (n >= 3 || d %3 == 0) {
        cout << "3 ";
    }
    if (d == 5) {
        cout << "5 ";
    }
    if (n>=3 || d == 7) {
        cout << "7 ";
    }
    if (n >= 9 || d == 9 || n >= 6 || ((d % 3 == 0) && (n >= 3))) {
        cout << "9 ";
    }

    cout << '\n';
}



int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}