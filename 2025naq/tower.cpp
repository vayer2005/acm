#include <bits/stdc++.h>
 
using namespace std; 
#define int long long
#define double long double

int r, c, n;


void solve() {
    cin >> r >> c >> n;

    int x, y;
    int frst[r][c];
    int sec[r][c];

    memset(frst, -1, sizeof(frst));
    memset(sec, -1, sizeof(sec));

    queue<vector<int>> q;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        x--; y--;
        q.push({i+1, x, y});
    }

    while (!q.empty()) {
        auto curr = q.front();
        int tow = curr[0];
        int i = curr[1];
        int j = curr[2];
        q.pop();

        if (i < 0 || i >= r || j < 0 || j >= c || sec[i][j] != -1 || frst[i][j] == tow) continue;

        if (frst[i][j] == -1) {
            frst[i][j] = tow;
        } else {
            sec[i][j] = tow;
        }

        q.push({tow, i+1, j});
        q.push({tow, i-1, j});
        q.push({tow, i, j+1});
        q.push({tow, i, j-1});

    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << frst[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << sec[i][j] << " ";
        cout << endl;
    }
    
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    
    return 0;
 
}