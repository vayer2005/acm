#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<string> grid;
vector<vector<vector<vector<int>>>> memo;
vector<vector<vector<vector<bool>>>> visiting;

int dx[] = {-1, 0, 1, 0}; // up, right, down, left
int dy[] = {0, 1, 0, -1};

// Returns minimum moves to reach T from (x,y) with last direction 'dir' and 'steps' consecutive moves
int dfs(int x, int y, int dir, int steps) {
    // Base cases
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#') {
        return INF;
    }
    
    if (grid[x][y] == 'T') {
        return 0;
    }
    
    // Check memoization
    if (memo[x][y][dir][steps] != -1) {
        return memo[x][y][dir][steps];
    }
    
    // Cycle detection
    if (visiting[x][y][dir][steps]) {
        return INF;
    }
    
    visiting[x][y][dir][steps] = true;
    int result = INF;
    
    // Try all 4 directions - exactly like BFS
    for (int new_dir = 0; new_dir < 4; new_dir++) {
        int nx = x + dx[new_dir];
        int ny = y + dy[new_dir];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') {
            continue;
        }
        
        int new_steps;
        if (new_dir == dir) {
            new_steps = steps + 1;
            if (new_steps > 3) continue; // Can't move more than 3 in same direction
        } else {
            new_steps = 1; // First step in new direction
        }
        
        int sub_result = dfs(nx, ny, new_dir, new_steps);
        if (sub_result != INF) {
            result = min(result, 1 + sub_result);
        }
    }
    
    visiting[x][y][dir][steps] = false;
    return memo[x][y][dir][steps] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Initialize memoization: [x][y][dir][steps]
    // dir: 0,1,2,3 and steps: 0,1,2,3
    memo.assign(n, vector<vector<vector<int>>>(m, 
                vector<vector<int>>(4, vector<int>(4, -1))));
    visiting.assign(n, vector<vector<vector<bool>>>(m, 
                   vector<vector<bool>>(4, vector<bool>(4, false))));
    
    // Find starting position
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
                break;
            }
        }
    }
    
    // Start with all possible directions from S - exactly like BFS
    int ans = INF;
    for (int d = 0; d < 4; d++) {
        ans = min(ans, dfs(sx, sy, d, 0));
    }
    
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}