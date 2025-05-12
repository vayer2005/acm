#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++) {
        cin >> arr[i];
        arr[i] = abs(arr[i]);
    }

    int tmp = arr[0];

    sort(arr, arr+n);
    int mid = n/2;


    if (tmp <= arr[mid]) {
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