#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m;
string grid[50];
vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
set<pair<int,int>> seen;
ll dfs(int r, int c) {
    seen.insert({r,c});
    
    if (grid[r][c] == 'P' || grid[r][c] == '#') {
        for (auto x : directions) {
            int nx = r + x[0];
            int ny = c + x[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (seen.find({nx,ny}) != seen.end()) continue;
            if (grid[nx][ny] != '.') {
                return dfs(nx,ny);
            }
        }
    } else if (grid[r][c] == '+' || grid[r][c] == '-' || grid[r][c] == '*' || grid[r][c] == '/') {
        vector<ll> ops;
        for (auto x : directions) {
            int nx = r + x[0];
            int ny = c + x[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (seen.find({nx,ny}) != seen.end()) continue;
            if (grid[nx][ny] != '.') {
                ops.push_back(dfs(nx,ny));
            }
        }
        if (ops[0] < ops[1]) swap(ops[0], ops[1]);

        if (grid[r][c] == '+') return ops[0] + ops[1];
        if (grid[r][c] == '-') return ops[0] - ops[1];
        if (grid[r][c] == '*') return ops[0] * ops[1];
        else return ops[0]/ops[1];

    } 

    return grid[r][c] - '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n >> m;

    int x,y;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'P') {
                x=i;
                y=j;
            }
        }
    }

    cout << dfs(x,y) << endl;
}

    



    

