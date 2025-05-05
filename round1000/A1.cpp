#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int even = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even = 1;
        } else {
            total += 1;
        }
    }
    if (even == 1) {
        cout << total + even << endl;
    } else {
        cout << total - 1 << endl;
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}