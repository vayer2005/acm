#include <bits/stdc++.h>

using namespace std;

#define int long long


int n, k;
const int mod = 67;
string s;
int dp[68][25][3]; // 0 = ends anything, 1 = s, 2 = sh
int ways[68][25][3];

void update(int i, int j, int z, int newcst, int newway) {
    if (dp[i][j][z] > newcst) {
        dp[i][j][z] = newcst;
        ways[i][j][z] = newway;
    } else if (dp[i][j][z] == newcst) {
        ways[i][j][z] += newway;
        ways[i][j][z] %= mod;
    }
}

signed main() {
    cin >> n >> k >> s;
    memset(dp, 0, sizeof(dp));
    memset(ways, 0, sizeof(ways));
    for (int i = 0;i < 68; i++) {
        for (int j = 0; j < 25; j++) {
            for (int z = 0; z < 3; z++) {
                dp[i][j][z] = 1e9;
            }
        }
    }
    ways[0][0][0] = 1;

    s = "." + s;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int z=0; z < 3; z++) {
                if (dp[i-1][j][z] >= (int)1e9) continue;
                int ns = dp[i-1][j][z] + (s[i] != 's');
                int ws = ways[i-1][j][z];
                update(i,j,1,ns,ws);

                if (z == 0) {
                    // place any other letter (not 's' or 'h')
                    int otherCost = (s[i] == 's') ? 1 : 0;
                    int otherWays = (s[i] == 's') ? 25 : 1;
                    int nnth = dp[i-1][j][0] + otherCost;
                    int wnth = (ways[i-1][j][0] * otherWays) % mod;
                    update(i,j,0,nnth,wnth);

                } else if (z == 1) {
                    // place any other letter (not 's' or 'h')
                    int otherCost = (s[i] == 's' || s[i] == 'h') ? 1 : 0;
                    int otherWays = (s[i] == 's' || s[i] == 'h') ? 24 : 1;
                    int nnth = dp[i-1][j][1] + otherCost;
                    int wnth = (ways[i-1][j][1] * otherWays) % mod;
                    update(i,j,0,nnth,wnth);

                    // place 'h'
                    int nsh = dp[i-1][j][1] + (s[i] != 'h');
                    int wsh = ways[i-1][j][1];
                    update(i,j,2,nsh,wsh);
                } else {
                    // place any other letter (not 's' or 'h')
                    int otherCost = (s[i] == 's' || s[i] == 'h') ? 1 : 0;
                    int otherWays = (s[i] == 's' || s[i] == 'h') ? 24 : 1;
                    int nnth = dp[i-1][j][2] + otherCost;
                    int wnth = (ways[i-1][j][2] * otherWays) % mod;
                    update(i,j,0,nnth,wnth);

                    // place 'h' completes one match
                    if (j + 1 <= k) {
                        int nxtnth = dp[i-1][j][2] + (s[i] != 'h');
                        int nxtw = ways[i-1][j][2];
                        update(i,j+1, 0, nxtnth, nxtw);
                    }
                }
            }
        }
    }

    int mnway=0;
    int mncst = 1e9;
    for (int i = 0; i < 3; i++) {
        if (dp[n][k][i] < mncst) {
            mncst = dp[n][k][i];
            mnway = ways[n][k][i];
        } else if (dp[n][k][i] == mncst) {
            mnway = (mnway + ways[n][k][i]) % mod;
        }
    }

    cout << mncst << " " << mnway << endl;
}