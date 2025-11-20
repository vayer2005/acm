#include <bits/stdc++.h>

using namespace std;

#define int long long


int n, k;
const int mod = 67;
string s;
int dp[68][25];
int ways[68][25];

int dfs(int ind, int left) {
    int diffs = 0;
    if (left == 0){
        ways[ind][left] = 1;
        dp[ind][left] = 0;
        return 0;
    }
    if (ind >= n) return 1e9;

    if (dp[ind][left] != -1) {
        return dp[ind][left];
    }
    
    if (ind + 2 >= n) {
        return 1e9;
    }
    diffs = (s[ind] != 's') + (s[ind+1] != 'h') + (s[ind+2] != 'h');

    int frst = diffs + dfs(ind+3, left-1);
    int nxt = dfs(ind+1, left);

    if (nxt == frst && nxt != 1e9) {
        if (ind+3 <= n){
            ways[ind][left] += ways[ind+3][left-1];
            ways[ind][left] %= mod;
        }
        if (ind +1 <= n) {
            ways[ind][left] += ways[ind+1][left];
            ways[ind][left] %= mod;
        }
        ways[ind][left] = max(ways[ind][left], 1LL);
    } else if (nxt > frst) {
         if (ind +3 <= n) {
            ways[ind][left] += ways[ind+3][left-1];
            ways[ind][left] %= mod;
        }
        ways[ind][left] = max(ways[ind][left], 1LL);
    } else {
        if (ind+1 <= n){
            ways[ind][left] += ways[ind+1][left];
            ways[ind][left] %= mod;
        }
        ways[ind][left] = max(ways[ind][left], 1LL);
    }
    dp[ind][left] = min(frst, nxt);
    return dp[ind][left];
}

int N = 100;
vector<int> fact(100, 0);

void initFactorial() {
    fact[0] = 1;
    for (int i = 1; i < N ; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
}
int binpow(int a, int b, int mod) {
    int res=1;
    while(b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

int inversemod(int a, int mod) {return binpow(a, mod-2, mod);}

int C(int n, int k) {
    if (k > n) {
        return 0;
    }
    int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
    int p2 = (1 * inversemod(fact[n-k], mod)) % mod;
    return (p1 * p2) % mod;
}


signed main() {
    
    cin >> n >> k;
    cin >> s;

    initFactorial();
    memset(dp, -1, sizeof(dp));

    int num = 0;

    for (int i = 0; i+2 < n; i++) {
        if (s[i] == 's' && s[i+1] == 'h' && s[i+2] == 'h') {
            num++;
        }
    }

    if (num == k) {
        cout << "0 1\n";
        return 0;
    } else if (num > k) {
        int tochange = num-k;
        int gway = C(num, tochange);
        int mult = tochange;
        while (mult > 0) {
            gway = (gway * 75) % 67;
            mult--;
        }
        
        cout << tochange << " " << gway << endl;
        return 0;

    }
    
    dfs(0, k);

    cout << dp[0][k] << " " << (ways[0][k] % 67) << endl;

    

}