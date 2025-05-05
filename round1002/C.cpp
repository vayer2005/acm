#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    int orig[n+1][n+1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> orig[i+1][j+1];
        }
    }

    vector<int> counts;
    for(int i = 1; i<=n;i++) {
        int cnt = 0;
        for(int j = n; j>= 1 and orig[i][j] == 1; j--) {
            cnt+=1;
        }
        counts.push_back(cnt);
    }

    sort(begin(counts), end(counts));
    int res = 0;
    for (int i : counts) {
        res += (i >= res);
    }

    cout << res << endl;


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