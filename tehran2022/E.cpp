#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
vector<string>grid;

set<pair<int,int>> res;

void dfs(int i, int j, int dir) {
    if (i >= n || j >= m || i < 0 || j < 0) {
        return;
    }
    if (grid[i][j] == 'o') {
        return;
    }

    res.insert({i,j});
    if (dir == 1) {
        dfs(i, j+1, dir);
    } else if (dir == 2) {
        dfs(i, j-1, dir);
    } else if (dir == 3) {
        dfs(i-1, j, dir);
    } else {
        dfs(i+1, j, dir);
    }
}

int main() {
    
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        grid.push_back(s);
    }

    // 1 -> right, 2->left, 3-> up, 4-> down;
    for (int i = 0; i < n; i++) {
        dfs(i,0,1); // row, col
        dfs(i,m-1, 2);
    }

    for (int i = 0; i < m; i++) {
        dfs(0,i,4); // row, col
        dfs(n-1,i, 3);
    }

    cout << res.size() << endl;
}