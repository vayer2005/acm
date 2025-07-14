#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
//# of leaves
int dfs1(int v, int p) {
    int res = 0;
    for (int x : adj[v]) {
        if (x != p) {
            res += dfs1(x, v);
        }
    }
    if (res == 0) {
        return 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

       
    int leaves = dfs1(0, -1);

 
    int rem = p%leaves;

    if (rem >= 2) {
        cout << ((p/leaves)+1) * 2 << endl;
    } else if (rem == 1) {
        cout << (p/leaves+1) + (p/leaves) << endl;
    } else {
        cout << 2 * (p/leaves) << endl;
    }


   
}