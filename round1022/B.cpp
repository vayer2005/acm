#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    ll n; ll x;
    cin >> n >> x;

    int bits=__builtin_popcountll(x);

    if (n <= bits) {
        cout << x << endl; 
        return;
    } else {
        
    }




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