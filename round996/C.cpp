#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {

    unordered_map<ll, ll> rowSum;
    unordered_map<ll, ll> colSum;


    int n; int m; string path;
    cin >> n >> m >> path;
    ll arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        ll curr = 0;
        for (int j = 0; j < m; j++) {
            curr += arr[i][j];
        }
        rowSum[i] = curr;
    }
    for (int j = 0; j < m; j++) {
        ll col = 0;
        for (int i = 0; i < n; i++) {
            col += arr[i][j];
        }
        colSum[j] = col;
    }

    int x = 0; int y = 0;

    for (int i = 0; i < path.size(); i++) {
        if (path[i] == 'D') {
            ll diff = 0 - rowSum[x];
            arr[x][y] = diff;
            rowSum[x] = 0;
            colSum[y] += diff;
            x+=1;
        } else {
            ll diff = 0 - colSum[y];
            arr[x][y] = diff;
            rowSum[x] += diff;
            colSum[y] = 0;
            y+=1;
        }
    }
    arr[x][y] = 0 - colSum[y];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}