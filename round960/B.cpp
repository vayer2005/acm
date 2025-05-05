#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    int arr[n];
    for(int i =0; i < n; i++) {
        arr[i] = 1;
    }
    int prev = -1;
    for(int i = y-2; i>=0; i--) {
        arr[i] = prev;
        prev = -1 * prev;
    }

    prev = -1;
    for(int i = x; i < n; i++) {
        arr[i] = prev;
        prev = -1 * prev;
    }

    for (int i = 0; i < n; i++) {
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