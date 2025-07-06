#include <bits/stdc++.h>

using namespace std;
#define int long long

const double EPS = 1e-9;
const double PI = 3.141592653589793;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int64_t a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> bits(64,0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 63; j++) {
            int64_t b = (a[i] >> j) & 1;
            if (b == 1) bits[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        int64_t val = 0;
        for (int j = 0; j < 64; j++) {
            if (bits[j] > 0) {
                val += (int64_t)(1 << j);
                bits[j]--;
            }
        }
        cout << val << " ";
    }
    cout << endl;

}