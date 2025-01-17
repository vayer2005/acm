#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int b[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int diff[n];
    
    for (int i = 0; i < n; i++) {
        diff[i] = b[i] - a[i];
    }

    sort(diff, diff + n);
    reverse(diff, diff+n);
    if (diff[0] > 0 && diff[1] > 0){
        cout << "NO\n";
    } else if (diff[0] > abs(diff[1])) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}