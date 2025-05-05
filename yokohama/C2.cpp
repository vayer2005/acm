#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


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
        grph[to].push_back({from, w});
    }

    vector<ll> dist(n + 1, LLONG_MAX); 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; 

        for (auto [v, w] : grph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    ll total = 0;

    for (int i = 1; i <=n; i++) {
        total += arr[i] * dist[i];
    }
    cout << total << endl;


}