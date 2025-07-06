#include <bits/stdc++.h>

using namespace std;
#define int long long

const double EPS = 1e-9;
const double PI = 3.141592653589793;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin >> n;
    int num = 1; int denom = 2;

    for (int i = 1;i < n; i++) {
        num += denom;
        int temp = denom;
        denom = num;
        num = temp;
    }

    cout << num << endl;



}