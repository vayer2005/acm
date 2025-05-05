#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll arr[n+1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (arr[1] > arr[2]) {
        cout << "NO\n";
        return; 
    }

    for (int i = 2; i < n; i++) {
        ll diff = arr[i-1] - arr[i-2];
        arr[i] = arr[i] - diff;
        arr[i-1] = arr[i-1] - diff;
        if (arr[i] > arr[i + 1]) {
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