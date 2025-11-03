
#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        grid.push_back(s);
    }

    int locs = 0;

    int r=-1; int c = -1;

    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,-1}, {-1, 1}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0' && i > 0 && i < n-1 && j > 0 && j < m-1) {
                bool fnd = true;

                for (auto x : dirs) {
                    if (grid[i+x.first][j+x.second] != 'O') fnd =false;
                }

                if (fnd == true) {
                    locs++;
                    r = i+1;
                    c = j+1;
                }
            }   
        }
    }

    if (locs == 0) {
        cout << "Oh no!\n";
    } else if (locs == 1) {
        cout << r << " " << c << endl;
    } else {
        cout << "Oh no! " << locs << " locations\n"; 
    }
}

signed main() {
  solve();
}