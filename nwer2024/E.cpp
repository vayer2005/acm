#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;

ll getPow(ll k) {
    if (k == 0) {
        return 1%n;
    }
    ll pw = getPow(k>>1);
    pw *= pw;
    pw %= n;
    if (k&1) {
        pw *= 2;
        pw %= n;
    }
    return pw;
}

int main() {

    ll k; string s;

    cin >> n >> k;
    cin >> s;

    ll pw = getPow(k);

    for (int i = 0; i < n; i++) {
        cout << s[(pw*i) % n];
    }
    cout << endl;


}