#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; 
    cin >> n;
    int a[n];
    int b[n];
    for (int i=0; i < n; i++) {
        cin >> a[i];
    }
    for (int i=0; i < n; i++) {
        cin >> b[i];
    }
    int dif = 0;
    for(int i = 0; i < n-1; i++) {
        if (a[i] > b[i+1]) {
            dif+=a[i] - b[i+1];
        }
    }
    dif+=a[n-1];
    cout << dif << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}