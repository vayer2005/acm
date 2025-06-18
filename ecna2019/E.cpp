#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 

int main() {
    int r, c, n; cin >> r >> c >> n;

    int arr[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }


    set<pair<int,int>>passes;

    for (int i = 1; i < r-1; i++) {
        for (int j = 1; j < c-1; j++) {
            if (arr[i][j] == -1 || arr[i-1][j] == -1 || arr[i+1][j] == -1 || arr[i][j+1] == -1 || arr[i][j-1] == -1) continue;
            if (arr[i][j] > arr[i][j+1] && arr[i][j] > arr[i][j-1] && 
            arr[i][j] < arr[i+1][j] && arr[i][j] < arr[i-1][j]) passes.insert({i,j});
        }
    }

    int dp[r][c+1][11];   
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j <= c; j++)
            for (int k = 0; k < 11; k++)
                dp[i][j][k] = 1e7;

    
    for (int i = 0; i < r; i++) {
            dp[i][c][0] = 0;
    }

    for (int i = c-1; i >= 0; i--) {
        for (int j = 0; j < r; j++) {
            if (arr[j][i] != -1) {
                if (passes.find({j,i}) != passes.end()) {
                    //At a pass
                    for (int pass = 1; pass <= 10; pass++) {
                        dp[j][i][pass] = min(dp[j][i][pass], arr[j][i] + dp[j][i+1][pass-1]);
                        if (j > 0) dp[j][i][pass] = min(dp[j][i][pass], arr[j][i] + dp[j-1][i+1][pass-1]);
                        if (j < r-1) dp[j][i][pass] = min(dp[j][i][pass], arr[j][i] + dp[j+1][i+1][pass-1]);
                    }
                } else {
                    for (int pass = 0; pass <= 10; pass++) {
                        dp[j][i][pass] = min(dp[j][i][pass],arr[j][i] + dp[j][i+1][pass]);
                        if (j > 0) dp[j][i][pass] = min(dp[j][i][pass], arr[j][i] + dp[j-1][i+1][pass]);
                        if (j < r-1) dp[j][i][pass] = min(dp[j][i][pass], arr[j][i] + dp[j+1][i+1][pass]);
                    }
                }
            }
        }
    }

    int minPath = 1e7;
    
    for (int i = 0; i < r; i++) {
        minPath = min(minPath, dp[i][0][n]);
    } 
    

    if (minPath >= 1e7) {
        cout << "impossible\n";
        return 0;
    }

    cout << minPath << endl;








}