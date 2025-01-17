#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; int m; int k;
    cin >> n >> m >> k;
    int mlist[m];
    set<int> klist;
    int curr;
    for(int i = 0; i < m; i++) {
        cin >> mlist[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> curr;
        klist.insert(curr);
    }

    string res;
    if (n == k) {
        //all 1s
        res = string(m,'1');
    } else if (n > k+1) {
        res = string(m,'0');
    } else {
        int missing;
        for (int i = 1; i <= n; i++) {
            if (klist.find(i) == klist.end()) {
                missing = i;
                break;
            }
        }
        res = "";
        for(int i = 0; i < m; i++) {
            if (mlist[i] == missing) {
                res += "1";
            } else {
                res += "0";
            }
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}