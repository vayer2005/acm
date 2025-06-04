int color[200001];
int vis[200001];
map<int,vector<int>> adj;


int dfs(int val) {
    vis[val] = 1;
    bool res = true;
    for (int x : adj[val]) {
        if (color[val] == color[x]) return false;
        if (vis[x] != 1) {
            color[x] = !color[val];
            res = res & dfs(x);
        }
    }
    return res;
}