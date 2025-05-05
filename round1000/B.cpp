#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int l; int r; int n;
    cin >> n >> l >> r;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> mins;
    for(int i = 0; i < r; i++) {
        mins.push_back(arr[i]);
    }

    sort(mins.begin(), mins.end());
    ll total = 0;
    for (int i = 0; i < r-l+1; i++) {
        total += mins[i];
    }

    ll curr = 0;
    vector<int> mins2;
    for(int i = l-1; i < n; i++) {
        mins2.push_back(arr[i]);
    }

    sort(mins2.begin(), mins2.end());
    for (int i = 0; i < r-l+1; i++) {
        curr += mins2[i];
    }

    cout << min(total, curr) << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}