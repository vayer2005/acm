#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; ll k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            arr[i] = 1;
        } else {
            arr[i] = -1;
        }
    }

    ll pref[n];
    pref[0] = arr[0]
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    // left and middle are positive

    

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