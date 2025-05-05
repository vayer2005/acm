#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; 
    cin >> n;

    int arr[n];

    for (int i =0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (2*i >= arr[i] || ((2*(n-i-1)) >= arr[i])) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}