#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    
    int n; ll k; 
    cin >> n >> k;

    ll arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll mn=arr[0]; ll mx=arr[0];

    ll tsum = 0;
    for(int i = 0; i < n; i++) {
        mx = max(arr[i], mx);
        mn = min(arr[i], mn);
        tsum += arr[i];
    }

    int nMx = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] == mx) {
            nMx += 1;
        }
    }

    if (mx - mn > k+1) {
        cout << "Jerry\n";
        return;
    }
    if (mx - mn > k && nMx > 1) {
        cout << "Jerry\n";
        return;
    }

    if (tsum % 2 == 1) {
        cout << "Tom\n";
        return;
    }
    cout << "Jerry\n";



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