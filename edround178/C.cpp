#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; string s;
    cin >> n >> s;

    int bLeft[n];

    if (s[n-1] == 'B') {
        bLeft[n-1] = 1;
    } else {
        bLeft[n-1] = 0;
    }

    for (int i = n-2; i >= 0; i--) {
        bLeft[i] = bLeft[i+1];
        if (s[i] == 'B') {
            bLeft[i] += 1;
        } 
    }

    for(int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            if (i == 0 && bLeft[i] == 1 && s[n-1] == 'B') {
                cout << "Alice\n";
                return;
            }
            if (i == n-1 && s[0] == 'A') {
                cout << "Alice\n";
                return;
            } else if (i != n-1 && bLeft[i] == 0) {
                cout << "Alice\n";
                return;
            }
        }
    }

    cout << "Bob\n";
    return;

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