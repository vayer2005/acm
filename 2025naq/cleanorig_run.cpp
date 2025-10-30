#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#define int long long

using namespace std;

int n, m, k;
set<pair<int,int>> blocks;
int filled = 0;


void dfs(int i, int j, vector<vector<int>> &dp) {
    if (i <= 0 || i > n) return;
    if (j <= 0 || j > m) return;
    if (dp[i][j] == 1) return;
    if (blocks.find({i,j}) != blocks.end()) return;

    dp[i][j]=1;
    filled++;
    dfs(i+1,j, dp);
    dfs(i-1, j, dp);
    dfs(i, j+1, dp);
    dfs(i, j-1, dp);
}


void solve() {

    cin >> n >> m >> k;
    map<int, vector<int>> rows;
    map<int, vector<int>> cols;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int r,c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        rows[r].push_back(c);
        cols[c].push_back(r);
        blocks.insert({r,c});
    }

    for (auto &it : rows) {
        sort(it.second.begin(), it.second.end());
    }

    for (auto &it : cols) {
        sort(it.second.begin(), it.second.end());
    }

    int mx = min(n,m);
    for (int i = 1; i <= n; i++) {
        int lb = -1e5;
        int rb = 1e18;
        int prv = 0;
        for (int j = 1; j <= m; j++) {
            if (blocks.find({i,j}) != blocks.end()) {
                lb = -1e5;
                rb = 1e18;
            } else {
                vector<int> &currcol = cols[j];
                auto it = lower_bound(currcol.begin(), currcol.end(), i);

                if (it == currcol.end()) {
                    rb = min(rb, n+1);
                    if (currcol.size() >= 1) lb = max(lb, currcol[currcol.size()-1]);
                    else lb = max(lb, 0LL);
                } else {
                    int idx = it - currcol.begin();
                    rb = min(rb, currcol[idx]);
                    if (idx > 0) {
                        lb = max(lb, currcol[idx-1]);
                    } else {
                        lb = max(lb, 0LL);
                    }
                }
                mx = min(mx, rb - lb-1);
            }
        }
    }

    for (int j = 1; j <= m; j++) {
        int lb = -1e5;
        int rb = 1e18;
        int prv = 0;
        for (int i = 1; i <= n; i++) {
            if (blocks.find({i,j}) != blocks.end()) {
                lb = -1e5;
                rb = 1e18;
            } else {
                vector<int> &currrow = rows[i];
                auto it = lower_bound(currrow.begin(), currrow.end(), j);

                if (it == currrow.end()) {
                    rb = min(rb, m+1);
                    if (currrow.size() >= 1) lb = max(lb, currrow[currrow.size()-1]);
                    else lb = max(lb, 0LL);
                } else {
                    int idx = it - currrow.begin();
                    rb = min(rb, currrow[idx]);
                    if (idx > 0) {
                        lb = max(lb, currrow[idx-1]);
                    } else {
                        lb = max(lb, 0LL);
                    }
                }
                mx = min(mx, rb - lb-1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (blocks.find({i,j}) == blocks.end()) {
                dfs(i,j,dp);
                if (filled + k == n * m) {   
                    cout << mx << endl;
                    return;
                } else {
                    cout << "-1\n";
                    return;
                }
            }
        }
    }
    

}

signed main() {

    solve();
    return 0;
}


