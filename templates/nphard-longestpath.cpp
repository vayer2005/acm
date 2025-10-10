

int longestPath(int n, vector<pair<int,int>> edges) {
    // Build adjacency list
    vector<vector<int>> adj(n);
    for (auto [u,v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, -1));

    // Initialize
    for (int u = 0; u < n; u++) {
        dp[1<<u][u] = 0;
    }

    int ans = 0;

    // Iterate over all subsets of nodes
    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == -1) continue;
            // Try to extend to neighbors
            for (int v : adj[u]) {
                if (!(mask & (1<<v))) { 
                    int newMask = mask | (1<<v);
                    dp[newMask][v] = max(dp[newMask][v], dp[mask][u] + 1);
                    ans = max(ans, dp[newMask][v]);
                }
            }
        }
    }

    return ans;
}