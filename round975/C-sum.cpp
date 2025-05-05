#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; int k;
    cin >> n >> k;

    int arr[n];

    for (int i =0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr + 0, arr + n);

    int l = 0; int r = n-1;

    int total = 0;
    while (l < r) {
        if (arr[l] + arr[r] == k) {
            total += 1;
            l++;
            r--;
        } else if (arr[l] + arr[r] > k) {
            r--;
        } else {
            l++;
        }
    }

    cout << total << endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}