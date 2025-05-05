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

    ll rpos[n];
    ll runp = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            runp += arr[i];
        }
        rpos[i] = runp;
    }
    ll rneg[n];
    ll runn = 0;
    for(int i = n-1; i >= 0; i--) {
        if (arr[i] < 0) {
            runn -= arr[i];
        }
        rneg[i] = runn;
    }
    ll cmax = 0;
    for(int i = 0; i < n; i++) {
        cmax = max(cmax, rpos[i] + rneg[i]);
    }

    cout << cmax << endl;


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