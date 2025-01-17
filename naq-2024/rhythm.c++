#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; int m;
    cin >> n >> m;

    ll expected[n];
    ll actual[m];

    int dp[n+1][m+1];

    for (int i =0; i < n;i++) {
        cin >> expected[i];
    }
    for (int i =0; i < m; i++) {
        cin >> actual[i];
    }

    for (int i = 0; i <= m; i++) {
        dp[n][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][m] = 0;
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            ll diff = abs(expected[i] - actual[j]);
            int toAdd = 0;
            if (diff <= 15) {
                toAdd = 7;
            } else if (diff <= 23) {
                toAdd = 6;
            } else if (diff <= 43) {
                toAdd = 4;
            } else if (diff <= 102) {
                toAdd = 2;
            }

            dp[i][j] = max({dp[i+1][j], dp[i][j+1], toAdd + dp[i+1][j+1]});
        }
    }



    cout << dp [0][0] << endl;


    
}

