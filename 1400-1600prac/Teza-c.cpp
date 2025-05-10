#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    int a[n];
    int b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    map<int, int> amp;
    int overlaps = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            overlaps++;
        }
        if (amp.find(b[i]) != amp.end()) {
            if (amp[b[i]] != a[i]) {
                cout << -1 << endl;
                return;
            }
        } else {
            amp[a[i]] = b[i];
        }
    }

    map<int, int> apos;
    for(int i = 0; i < n; i++) {
        apos[a[i]] = i;
    }

    if (n%2 == 1) {
        if (overlaps != 1) {
            cout << -1 << endl;
            return;
        }




    } else {
        if (overlaps != 0) {
            cout << -1 << endl;
            return;
        }

    }

    cout << 1 << endl;
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