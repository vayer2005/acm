#include <bits/stdc++.h>

//#define int long long
using namespace std;


signed main() {
    int n; cin >> n;
    string st[n];
    for (int i  =0; i < n; i++) {
        cin >> st[i];
    }
    string t;
    cin >> t;

    for (string s : st) {
        int tInd = 0;
        for (char x : s) {
            if (x == t[tInd]) {
                tInd++;
                if (tInd == t.size()) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    string ans = "";
    vector<int> ind(n,0);
    int tInd = 0;
    vector<int> diff;
    vector<int> same;
    set<int> travInds;
    for (int i = 0; i < n; i++) travInds.insert(i);
    while (true) {
        diff.clear();
        same.clear();
        for (int i : travInds) {

            if (st[i][ind[i]] == t[tInd]) same.push_back(i);
            else diff.push_back(i);
        }
        if (same.size() == 0 && diff.size() == 0) break;

        else if (diff.size() != 0) {
            for (int x : diff) {
                ans += st[x][ind[x]];
                ind[x]++;
                if (ind[x] == st[x].size()) travInds.erase(x);
            }
            continue;
        } else {
            for (int x : same) {
                ind[x]++;
                if (ind[x] == st[x].size()) travInds.erase(x);
            }
            ans += t[tInd];
            tInd++;
        }
    }

    cout << "YES\n";
    cout << ans << endl;
    
  
}
