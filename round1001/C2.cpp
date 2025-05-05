#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    vector<ll> dp(n,0);

    for(int i = 0; i < n;i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        if (i == 0) {
            if (arr[i] == 0) {
                dp[i] = 2;
            } else {
                dp[i] = 1;
            }
            continue;
        } if (i==1) {
            if (arr[i] == arr[i-1]) {
                dp[i] += dp[i-1]+1;
            }
            continue;
        }
        if (arr[i] == arr[i-1]) {
            dp[i] += dp[i-1];
        } if (arr[i] == arr[i-2] + 1) {
            dp[i] += dp[i-2];
        }
    }


    if (dp.size() >= 2) {
        cout << dp[n-1] + dp[n-2] << endl;
    } else {
        cout << dp[n-1] << endl;
    }




    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}