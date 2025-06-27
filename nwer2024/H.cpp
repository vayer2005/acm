#include <bits/stdc++.h>
 
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;

    cout << "? " << n << " 1\n";
    cout.flush();
    int x;
    cin >> x;
    int nxt = n-x;
    if (nxt == 0) {
        cout << "! " << n << " 1\n";
        cout.flush();
        return 0;   
    }

    cout << "? " << n-x << " 1\n";
    cout.flush();
    int y;
    cin >> y;

    cout << "! " << x << " " << y << endl;
    cout.flush();
}   