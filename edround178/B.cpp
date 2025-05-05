#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll maxLeft[n];
    ll suffix[n];
    maxLeft[0]=0;
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i-1], arr[i-1]);
    }

    suffix[n-1] = arr[n-1];

    for(int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] + arr[i];
    }
    ll res;
    for(int i = n-1; i >= 0; i--) {
        res = max(suffix[i], suffix[i]-arr[i]+maxLeft[i]);
        cout << res << " ";
    }
    cout << endl;
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