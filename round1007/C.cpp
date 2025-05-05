#include <bits/stdc++.h>
//#define mp make_pair

using namespace std;
typedef long long ll;

map<int, vector<int>> mp;
set<int> visited;

void dfs(int val) {
    
    if (visited.find(val) != visited.end()) {
        return;
    }
    vector<int> children = mp[val];

    visited.insert(val);
    for(int i = 0; i < children.size(); i++) {
        dfs(children[i]);
    }
    cout << val << " ";
}



void solve() {
    mp.clear();
    visited.clear();
    int n; int st; int en;
    cin >> n >> st >> en;

    int from; int to;
    
    
    for(int i = 0; i < n-1; i++) {
        cin >> from >> to;
        
        mp[to].emplace_back(from);
        mp[from].emplace_back(to);
    
    }
    
    dfs(en);
    cout << endl;    
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}