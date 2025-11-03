#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n, x0, y0, d;
    std::cin >> n >> x0 >> y0 >> d;
    vector<vector<vector<int>>> dp(d + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    dp[0][x0][y0] = 1;
    for (int i = 1; i <= d; i++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                const int lowerY = y > 1 ? y - 1 : 1;
                const int upperY = y < n ? y + 1 : n;
                const int lowerX = x > 1 ? x - 1 : 1;
                const int upperX = x < n ? x + 1 : n;
                dp[i][lowerX][lowerY] += dp[i-1][x][y];
                dp[i][upperX][lowerY] += dp[i-1][x][y];
                dp[i][lowerX][upperY] += dp[i-1][x][y];
                dp[i][upperX][upperY] += dp[i-1][x][y];
            }
        }
        for (int x = 1; x <= n; x++) {
            dp[i][x][x] = 0;
        }
    }
    int total = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            total += dp[d][x][y];
        }
    }
    int paths = pow(4, d);
    int comp = paths - total;
    int gc = std::gcd(comp, paths);
    comp /= gc;
    paths /= gc;
    std::cout << comp << "/" << paths << std::endl;
}