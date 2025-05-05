#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int k;
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if (n == k) {
        for (int i = 1; i < n; i+=2) {
            if (arr[i] != (i/2)+1) {
                cout << (i/2) + 1 << endl;
                return;
            }
        }
        cout << (n/2) + 1<< endl;
        return;
    }
    k /= 2;
    for (int i = 1; i <= n - 2 * k + 1; i++) {
            if (arr[i] != 1) {
                cout << "1\n";
                return;
            }
    }
    cout << "2\n";


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