#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int a[5];

    cin >> a[0] >> a[1] >> a[3] >> a[4];

    a[2] = a[0] + a[1];
    ll fib = 0;
    ll curfib = 0;
    for(int i = 2; i < 5; i++){
        if (a[i-2] + a[i-1] == a[i]) {
            curfib += 1;
        }
    }
    fib = max(curfib, fib);

    a[2] = a[3] - a[1]; 
    curfib = 0;
    for(int i = 2; i < 5; i++){
        if (a[i-2] + a[i-1] == a[i]) {
            curfib += 1;
        }
    }
    fib = max(curfib, fib);

    a[2] = a[4] - a[3]; 
    curfib = 0;
    for(int i = 2; i < 5; i++){
        if (a[i-2] + a[i-1] == a[i]) {
            curfib += 1;
        }
    }
    fib = max(curfib, fib);

    cout << fib << endl;

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}