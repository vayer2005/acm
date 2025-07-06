#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int seen[501][501][2];
int n; 
int a, b, c, d;

void dfs(int x, int y, int prev) {
    if (x >= n || x < 0 || y >= n || y < 0) {
        return;
    }
    if (seen[x][y][prev]) return;
    seen[x][y][prev] = 1;
    if (prev) {
        dfs(x+a, y+b, 0);
        dfs(x+a, y-b, 0);
        dfs(x-a, y+b, 0);
        dfs(x-a, y-b, 0);
        dfs(x+b, y+a, 0);
        dfs(x+b, y-a, 0);
        dfs(x-b, y+a, 0);
        dfs(x-b, y-a, 0);
    } else {
        dfs(x+c, y+d, 1);
        dfs(x+c, y-d, 1);
        dfs(x-c, y+d, 1);
        dfs(x-c, y-d, 1);
        dfs(x+d, y+c, 1);
        dfs(x+d, y-c, 1);
        dfs(x-d, y+c, 1);
        dfs(x-d, y-c, 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(seen, 0, sizeof(seen));
    cin >> n;
    cin >> a >> b >> c >>d;


    dfs(0,0,true);
    dfs(0,0, false);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j =0; j < n; j++) {
            ans += max(seen[i][j][0], seen[i][j][1]);
        }
    }

    cout << ans << endl;

    
}