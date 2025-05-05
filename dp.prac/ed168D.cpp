#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

int vals[200007];
map<int, vector<int>> edg;
int n;

int dfs(int nd) {
    
    vector<int> children = edg[nd];
    if (children.size() == 0) {
        return vals[nd];
    }

    int mval = (1e9) + 1;
    int curr = vals[nd];
    for(int i = 0; i < children.size(); i++) {
        mval = min(mval, dfs(children[i]));
    }

    if (curr >= mval) {
        return mval;
    } else {
        return floor((curr + mval)/2);
    }

} 


void solve() {
    edg.clear();
    cin >> n;

    for(int i = 1; i < n+1; i++) {
        cin >> vals[i];
    }

    int par;
    for(int i = 2; i <= n; i++) {
        cin >> par;
        edg[par].push_back(i);
    }
    vector<int> children = edg[1];
    if (children.size() == 0) {
        cout << vals[1] << endl;
        return;
    }

    int minval = (1e9)+1;
    for(int i = 0; i < children.size(); i++) {
        minval = min(minval, dfs(children[i]));
    }

    cout << vals[1] + minval << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}