#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    
    int ans[n];

    int u, v, x;
    vector<vector<int>> twr;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> x;
        twr.push_back({u, v, x});
    }

    for (int i = 0; i < n; i++) {
        int x= twr[i][0]; int y = twr[i][1]; int h = twr[i][2];

        int minH = h;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (twr[j][2] < h) continue;
            int nx = twr[j][0]; int ny = twr[j][1];
            int ndis = (int)sqrt((nx-x)*(nx-x) + (ny-y) * (ny-y));
            minH = min(minH, ndis);
        }

        cout << minH << endl;
    }
}