#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n, k;
    cin >> n >> k;

    ll r = (n/k) + 1;
    ll l = 0;

    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (l <= r) {
        ll mid = (l + r) / 2;
        int groups = 0;
        set<ll> vals;
        for(int i = 0; i < n; i++) {
            if (arr[i] < mid) {
                vals.insert(arr[i]);
            }
            if (vals.size() == mid) {
                groups++;
                vals.clear();
            }
        }

        if (groups >= k) {
            //Works mid = l
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << r << endl;



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