#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> prefix(2*n+1, 0);
    vector<int> count(2*n+1, 0);
    unordered_map<int,int> vals;
    int l; int r;
    vector<vector<int>> pairs;

    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        if (l == r) {
            count[l] = 1;
            if (vals.find(l) != vals.end()) {
                vals[l] += 1;
            } else {
                vals[l] = 1;
            }
        }
        vector<int> p(2,0);
        p[0] = l;
        p[1] = r;
        pairs.push_back(p);
    }

    for(int i = 1; i <= 2*n; i++) {
        prefix[i] = count[i] + prefix[i-1];
    }
    string res = "";
    for (int i = 0; i < pairs.size(); i++) {
        l = pairs[i][0];
        r = pairs[i][1];
        if (l == r) {
            if (vals[l] == 1) {
                res += "1";
            } else {
                res += "0";
            }
        } else {
            if (prefix[r] - prefix[l-1] == r - l + 1) {
                res += "0";
            } else {
                res += "1";
            }
        }
    }

    cout << res << endl;

    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}