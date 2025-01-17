#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n; ll x; ll y;

    cin >> n >> x >> y;
    ll tsum=0;
    vector<ll> arr(n,0);
    for(int i = 0; i < n;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    ll currSum;
    int j = 0;
    ll ans = 0;
    for(int i =0; i < arr.size(); i++) {
        tsum += arr[i];
    }

    int l = 0;
    for(int i = n-1; i > -1; i--) {
        while (l <= i && tsum - arr[i] - arr[l] > y) {
            l++;
        }
        
        ans += max(i-l, 0);
    }

    int r = 0;
    for (int i = n-1; i > -1; i--) {
        while (r <= i && tsum - arr[i] - arr[r] >= x) {
            r++;
        }
        if (r >= i) {
            break;
        }
        ans += r - i;
    }

    cout << ans << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}