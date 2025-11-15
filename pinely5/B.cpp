#include <bits/stdc++.h>


#define int long long

using namespace std;



void solve() {
    int n;
    cin >> n;

    vector<string> grid;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    vector<pair<int, int>> black_cells;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                black_cells.push_back({i, j});
            }
        }
    }

    if (black_cells.empty()) {
        cout << "YES\n";
        return;
    }

    // Check condition 1: All black cells on two neighboring diagonals (x+y orientation)
    int min_sum = 1000, max_sum = -1000;
    for (auto [x, y] : black_cells) {
        min_sum = min(min_sum, x + y);
        max_sum = max(max_sum, x + y);
    }
    if (max_sum - min_sum <= 1) {
        cout << "YES\n";
        return;
    }

    // Check condition 2: All black cells on two neighboring diagonals (x-y orientation)
    int min_diff = 1000, max_diff = -1000;
    for (auto [x, y] : black_cells) {
        min_diff = min(min_diff, x - y);
        max_diff = max(max_diff, x - y);
    }
    if (max_diff - min_diff <= 1) {
        cout << "YES\n";
        return;
    }

    // Check condition 3: All black cells in a 2×2 square
    int min_x = 1000, max_x = -1000;
    int min_y = 1000, max_y = -1000;
    for (auto [x, y] : black_cells) {
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }
    if (max_x - min_x <= 1 && max_y - min_y <= 1) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

signed main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
