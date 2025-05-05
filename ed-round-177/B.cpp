#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    ll n; ll k; ll x;

    cin >> n >> k >> x;

    ll arr[n];
    ll temp = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        temp += arr[i];
    }


    ll total = 0;
    ll sum = 0;
    while (sum < x) {
        sum += temp;

        total += n;
        if (total > n*k) {
            break;
        }
    }
    int l = 0;
    while (sum >= x) {
        sum -= arr[l];
        total -= 1;
        l+=1;
    }

    ll ans = n * k - total;
    if (ans < 0) {
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
    
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