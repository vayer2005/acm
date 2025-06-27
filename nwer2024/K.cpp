#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
int n, m, k;
vector<double> p;
vector<int> d1, d2, kr;
 
signed main() {
    
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    p.resize(n+1, 0.0);
    d1.resize(n+1, 1e18);
    d2.resize(n+1, 1e18);
 
    int u, v, l;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> l;
        adj[u].push_back({v,l});
        adj[v].push_back({u,l});
    }
 
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(n+1, false);
 
    pq.push({0,1});
    d1[1] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int nd = pq.top().second;
        pq.pop();
        
        if (visited[nd]) continue;
        visited[nd] = true;
        
        for (auto x : adj[nd]) {
            int newd = x.second;
            int nxt = x.first;
            if (!visited[nxt] && d1[nxt] > newd + dist) {
                d1[nxt] = newd + dist;
                pq.push({newd + dist, nxt});
            }
        }
    }
 
    fill(visited.begin(), visited.end(), false);
    pq.push({0, n});
    d2[n] = 0;
 
    while (!pq.empty()) {
        int dist = pq.top().first;
        int nd = pq.top().second;
 
        pq.pop();
        
        if (visited[nd]) continue;
        visited[nd] = true;
        
        for (auto x : adj[nd]) {
            int newd = x.second;
            int nxt = x.first;
            if (!visited[nxt] && d2[nxt] > newd + dist) {
                d2[nxt] = newd + dist;
                pq.push({newd + dist, nxt});
            }
        }
    }
 
    vector<pair<int,int>> pq2(k);
    bool found = false;
    double prob;
    for (int i=0; i <k; i++) {
        int val;
        cin >> val >> prob;
        if (prob >= 0.99999) {
            found = true;
        }
        p[val] = prob;
        pq2[i].first = d1[val] + d2[val];
        pq2[i].second = val;
    }
 
    if (!found) {
        cout << "impossible\n";
        return 0;
    }
 
    sort(pq2.begin(), pq2.end());

    cout << fixed << setprecision(7) << res << endl;
 
 
}   