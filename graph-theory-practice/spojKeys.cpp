#include<stdio.h>
#include<vector>
#include<queue>
#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    bool vis[n+1];
	int par[n+1];
	for(int i=0; i<=n; i++){
		vis[i]=false;
		par[i]=0;
	}
    vector<int> keys[100001];


    int numkeys,val;
    for(int i = 1; i < n; i++) {
        cin >> numkeys;
        for(int j=0; j < numkeys; j++) {
            cin >> val;
            keys[i].push_back(val);
        }
        sort(keys[i].begin(), keys[i].end());
    }

    queue<int> q; // val, par
    bool flag = false;
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == n) {
            flag = true; break;
        }


        for (auto x : keys[v]) {
            if (!vis[x]) {
                vis[x] = true;
                par[x] = v;
                q.push(x);
            }
        }
    }

    if (flag) {
        vector<int> sol;
        int curr = par[n];

        while (curr != 1) {
            sol.push_back(curr);
            curr=par[curr];
        }

        sol.push_back(1);
        cout << sol.size() << endl;
        for(int i = sol.size()-1; i >=0; i--) {
            cout << sol[i] << " ";
        }
        cout << endl;
    } else cout << "-1\n";

    cout << "\n";


} 
signed main()
{
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}