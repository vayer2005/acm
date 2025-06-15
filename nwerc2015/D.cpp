#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
int n;

ll r, p;
vector<ll> dp(N+5, -1);

ll fn(int x) {
    if (x == 1) return 0;
    if (dp[x] != -1) return dp[x];

    ll res = 1LL*(x-1)*p+r;

    for (int i = 2; i <= x; i++) {
        int md = x % i;
		int gsz1 = (x / i) + (md != 0);

		res = min(res, p * (i-1) + r + fn(gsz1));
    }
    dp[x] = res;
    return res;
}

int main() {
    
    cin >> n >> r >> p;

    dp[1] = 0;

    cout << fn(n) << endl;

    
    
}