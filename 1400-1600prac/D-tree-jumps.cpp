#include <bits/stdc++.h>
//#define mp make_pair

using namespace std;
typedef long long ll;


map<int, vector<int>> lvl;
map<int, set<int>> mp;
map<int, ll> dp;
map<int, ll> dpsum;

void dfs(int l) {
    if (l == 1) {
        dp[1] = (1 + dpsum[l+1]%998244353)%998244353;
        return;
    }
    vector<int> nodes = lvl[l];
    ll tot = 0;
    for (int n : nodes) {
        ll res = 1 + dpsum[l+1];
        ll sub = 0;
        for (int c : mp[n]) {
            sub += dp[c];
        }
        res -= sub;
        res %= 998244353;
        dp[n] = res;
        tot += res;
    }
    dpsum[l] = tot;
    dfs(l-1);
}

void solve() {
    int n;
    cin >> n;

    lvl.clear();
    mp.clear();
    dp.clear();
    dpsum.clear();

    int val;
    for(int i = 2; i < n+1; i++) {
        cin >> val;
        mp[val].insert(i);
    }

    
    queue<int> q;

    q.push(1);

    int lv = 1;
    while (!q.empty()) {
        int qlen = q.size();

        for (int i = 0; i < qlen; i++) {
            int qval = q.front();
            lvl[lv].push_back(qval);
            q.pop();
            for (int x : mp[qval]) {
                q.push(x);
            }
        }
        lv++;
    }

    int maxLvl = 0;
    for (auto &pair : lvl) {
        maxLvl = max(maxLvl, pair.first);
    }

    dpsum[maxLvl + 1] = 0;

    dfs(maxLvl);

    cout << dp[1] << endl;
    

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