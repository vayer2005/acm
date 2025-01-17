#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i =0;i < n; i++) {
        cin >> arr[i];
    }

    for(int i =0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            if (arr[i] < 2 * arr[i+1]) {
                cout << "YES\n";
                return;
            }
        } else {
            if (arr[i] * 2 > arr[i+1]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";


}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}