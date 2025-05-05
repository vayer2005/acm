#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; ll x;
    cin >> n >> x;

    int arr[n];

    for (int i =0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if (sum == x * n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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