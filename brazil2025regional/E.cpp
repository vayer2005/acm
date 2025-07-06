#include <bits/stdc++.h>

using namespace std;
#define int long long

const double EPS = 1e-9;
const double PI = 3.141592653589793;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool zero = true;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] < a[i][j-1]) {
                zero = false;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            if (a[i][j] < a[i-1][j]) {
                zero = false;
            }
        }
    }
    if (zero) {
        cout << "0\n";
        return 0;
    }


    bool one = true;
    for (int i = 0; i < n; i++) {
        for (int j = n-2; j >= 0; j--) {
            if (a[i][j] < a[i][j+1]) {
                one = false;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            if (a[i][j] < a[i-1][j]) {
                one = false;
            }
        }
    }
    if (one) {
        cout << "1\n";
        return 0;
    }

    bool two = true;
    for (int i = 0; i < n; i++) {
        for (int j = n-2; j >= 0; j--) {
            if (a[i][j] < a[i][j+1]) {
                two = false;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = n-2; i >=0; i--) {
            if (a[i][j] < a[i+1][j]) {
                two = false;
            }
        }
    }

    if (two) {
        cout << "2\n";
        return 0;
    }
    cout << "3\n";



}