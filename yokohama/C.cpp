#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;
const int INF = 1e9;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; int m;
    cin >> n >> m;

    int arr[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    map<int, vector<pair<int, int>>> grph;
    int from; int to; int w;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> w;
        grph[from].push_back({to, w});
        grph[to].push_back({from, w}); // Make graph undirected
    }

    vector<int> dist(n+1, INF);
    dist[1] = 0;
    ll total = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int curr = pq.top().second;
        int path = pq.top().first;
        pq.pop();

        if (path > dist[curr]) continue; // Skip if we found a better path already

        total += path * arr[curr]; // Add path * vertex weight to total

        for (auto [to, w] : grph[curr]) {
            if (path + w < dist[to]) {
                dist[to] = path + w;
                pq.push({dist[to], to});
            }
        }
    }

    cout << total << endl;
}