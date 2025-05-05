#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    int arr[n];

    for (int i =0;i < n;i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    cout << arr[n-1] - arr[0] << endl;

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