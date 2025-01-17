#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; int k;
    cin >> n >> k;
    ll arr[n];
    map<ll, int> occur;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        if (occur.find(arr[i]) == occur.end()) {
            occur[arr[i]] = 1;
        } else {
            occur[arr[i]] = occur[arr[i]] + 1;
        }
    }

    vector<int> counts;
    int num = 0;
    for(auto &it : occur) {
        num += 1;
        counts.push_back(it.second);
    }

    sort(counts.begin(), counts.end());

    int total = 0;
    int less = 0;
    for(int i = 0; i < counts.size()-1; i++) {
        if (total + counts[i] <= k) {
            total += counts[i];
            less += 1;
        } else {
            break;
        }
    }
    cout << num - less << endl;


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