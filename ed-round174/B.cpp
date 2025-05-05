#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int m;
    cin >> n >> m;

    int arr[n][m];

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    map<int,int> occur;
    for(int i = 0; i < n; i++) {
        for(int j=0;j<m; j++) {
            int in; int jn;
            in = i + 1;
            jn = j;
            if (in < n && arr[in][jn] == arr[i][j]) {
                occur[arr[i][j]] = 2;
                continue;
            }

            in = i - 1;
            jn = j;
            if (in >= 0  && arr[in][jn] == arr[i][j]) {
                occur[arr[i][j]] = 2;
                continue;
            }

            in = i;
            jn = j+1;
            if (jn < m && arr[in][jn] == arr[i][j]) {
                occur[arr[i][j]] = 2;
                continue;
            }

            in = i;
            jn = j-1;
            if (jn >= 0  && arr[in][jn] == arr[i][j]) {
                occur[arr[i][j]] = 2;
                continue;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j=0;j<m; j++) {
            if (occur[arr[i][j]] != 2) {
                occur[arr[i][j]] = 1;
            }
        }
    }

    int maxSeen = 0;
    int total = 0;
    for (auto &it : occur) {
        maxSeen = max(maxSeen, it.second);
        total += it.second;
    }

    cout << total - maxSeen << endl;

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