#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    s = s;
    int dp[n+1][10];
    memset(dp, 0, sizeof(dp));

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int curr = s[i-1] - '0';
        dp[i][curr] += 1;
        for (int j = 0; j < 10; j++) {
            if (j <= curr) {
                dp[i][curr] += dp[i-1][j];
            } else {
                dp[i][j] += dp[i-1][j];
            }
            sum += dp[i][j] * j;
        }
    }

    int denom = n * (n+1)/2;
    int integ = sum / denom;
    sum %= denom;
    int gcd = sum == 0 ? 1 : std::gcd(sum, denom);
    sum /= gcd;
    denom /= gcd;
    if (integ != 0) {
        std::cout << integ;
    }
    if (sum != 0) {
        if (integ != 0) {
            cout << " ";
        }
        std::cout << sum << "/" << denom << endl;
    } else {
        if (integ == 0) {
            cout << 0;
        }
        std::cout << endl;
    }
}

signed main() {
  solve();
}
