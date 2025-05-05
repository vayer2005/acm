#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    int l = -1;
    int r = -1;

    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0 && l == -1) {
            l = i;
        }
        if (arr[i] == 0 && l != -1) {
            r = i;
        }
    }
    if (l == -1) {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }

    if (l == 1 && r == n) {
        cout << 3 << endl;
        cout << n-1 << " " << n << endl;
        cout << 1 << " " << n-2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    
    if (l == r) {
        if (l < n) {
            cout << 2 << endl;
            cout << l << " " << l+1 << endl;
            cout << 1 << " " << n-1 << endl;
        } else {
            cout << 2 << endl;
            cout << l-1 << " " << l << endl;
            cout << 1 << " " << n-1 << endl;
        }
        return;
    }

    cout << 2 << endl;
    cout << l << " " << r << endl;
    cout << 1 << " " << n-(r-l) << endl;
    return;
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