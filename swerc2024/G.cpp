#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    
    ll r;
    int n;
    cin >> r >> n;

    ll d[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    ll p1 = 0;
    ll p2 = r;

    for (int i = 0; i < n; i++) {
        if (d[i] <= 0) {
            p1 = max(0LL, p1 + d[i]);
            p2 = max(0LL, p2 + d[i]);
        } else {
            p1 = min(r, p1 + d[i]);
            p2 = min(r, p2 + d[i]);
        }
    }

    if (p1 == p2) {
        cout << p1 << endl;
        return 0;
    }
    cout << "uncertain\n";

  
}


