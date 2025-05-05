#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    int arr[n];
    for(int i =0; i < n; i++) {
        cin >> arr[i];
    }

    ll pref[n];
    pref[0] = arr[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    set<ll> seen;
    seen.insert(0);
    int total = 0;
    for(int i = 0; i < n; i++) {
        if (seen.find(pref[i]) != seen.end()) {
            seen.clear();
            seen.insert(pref[i]);
            total += 1;
        } 
        seen.insert(pref[i]);
    }

    cout << total << endl;

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