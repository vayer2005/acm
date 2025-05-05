#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int m;
    cin >> n >> m;

    ll arr[n][m];

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, ll>> rowSums;

    for (int i = 0; i < n; i++) {
        ll rsum = 0;
        for(int j = 0; j < m; j++) {
            rsum += arr[i][j];
        }
        pair p = mp(i, rsum);
        rowSums.push_back(p);
    }

    sort(rowSums.begin(), rowSums.end(), [](auto &left, auto &right) {
    return left.second > right.second;});
    ll total = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            total += arr[rowSums[i].first][j] * (n*m - (i*m + j));
        }
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