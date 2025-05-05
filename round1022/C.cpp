#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    vector<ll> arr;

    arr.push_back(0);
    ll val;
    ll prev = 0;
    for(int i = 0; i < n; i++) {
        cin >> val;
        if (val != prev) {
            arr.push_back(val);
        }
        prev = val;
    }
    arr.push_back(0);

    int ans = 0;
    for(int i = 1; i < arr.size()-1; i++) {
        if (arr[i] > arr[i+1] && arr[i] >= arr[i-1]) {
            ans+=1;
        }
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