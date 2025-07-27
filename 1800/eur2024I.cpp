#include <bits/stdc++.h>

#define int long long
using namespace std;

bool dfs(int v, int p, vector<int> &visit, vector<int> &color, map<int,vector<int>> &adj) {
    visit[v] = 1;
    bool res = true;
    for (int x : adj[v]) {
        if (x == p) continue;
        if (color[x] != -1) {
            if (color[x] == color[v]) return false; continue;
        }

        color[x] = !color[v];
        res = res & dfs(x, v, visit, color, adj);
    }
    return res;
}

signed main() {

    int n;
    cin >> n;
    vector<vector<int>> circles;
    map<int, vector<int>> adj;

    int x, y, r;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> r;
        circles.push_back({x,y,r});
    }

    for (int i = 0; i < n; i++) {
        auto c1 = circles[i];
        for (int j = i+1; j < n; j++) {
            auto c2 = circles[j];
            int x1 = c1[0]; int x2=c2[0];
            int y1 = c1[1]; int y2 = c2[1];
            long long dx = x2 - x1, dy = y2 - y1;
            long long d2 = dx*dx + dy*dy;             // (distance)^2
            long long sumR = c1[2] + c2[2];
            if (d2 == 1LL * sumR * sumR)   // externally tangent
            {
                //tangent add edge
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }


   
    vector<int> vis(n, 0);

    for (int i = 0; i < n; ++i) {
        vector<int> color(n,-1);
        if (!vis[i]) {
            color[i] = 0;
            bool res = dfs(i, -1, vis, color, adj);
            if (!res)continue;
        }
        int w = 0; int b = 0;
        for (int x : color) {
            if (x == 0) w++;
            else if (x == 1) b++;
        }
        if (w != b) {
            cout << "YES\n";
            return 0;
        }
    }

   cout << "NO\n";
   return 0;
  
}
