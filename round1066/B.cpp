#include <bits/stdc++.h>

using namespace std;

#define int long long


void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;

    int n4 = 0;
    int n8 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '4') {
            n4++;
        } else {
            n8++;
        }
    }
    int top = n4 + n8;

    x = abs(x);
    y = abs(y);
    for (int i = 0; i <= n8; i++) {
        if (x == i && y <= top) {
            cout << "YES\n";
            return;
        } 
        if (y == i && x <= top) {
            cout << "YES\n";
            return;
        }
    }
    top -=1;
    for (int i = n8+1; i <= n4+n8; i++) {
        if (x == i && y <= top) {
            cout << "YES\n";
            return;
        }
        if (y == i && x <= top) {
            cout << "YES\n";
            return;
        }
        top--;
    }

    cout << "NO\n";




    


}


signed main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    
    

}