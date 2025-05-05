#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    int arr[n];
    ll rsum = 0;

    for (int i = 0; i < n; i++) {
        arr[i] = i+1;
    }

    for(int i = 0; i < n; i++) {
        long double val = sqrt(rsum + arr[i]);
        if (floor(val) == ceil(val)) {
            if (i >= n-1) {
                cout << -1 << endl;
                return;
            }
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        rsum += arr[i];
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
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