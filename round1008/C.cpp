#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    ll arr[2 * n];

    for (int i = 0; i < 2*n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 2 * n);
    reverse(arr, arr + 2 * n);

    ll bsum = 0;
    ll minArr[n-1];
    ll maxArr[n+1];
    for (int i = 0; i < 2 * n; i++) {
        if (i <= n) {
            bsum += arr[i];
            maxArr[i] = arr[i];
        } else {
            bsum -= arr[i];
            minArr[i-n-1] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == n-1) {
            cout << maxArr[i] << " " << bsum << " " << maxArr[i+1] <<endl;
            return;
        }
        cout << maxArr[i] << " " << minArr[i] << " ";
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