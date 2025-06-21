#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    int n;
    cin >> n;

    vector<int> adj[n+1];

    vector<int> in(n+1, 0);

    int p, v;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        for (int j =0;j < p; j++) {
            cin >> v;
            in[v]++;
            adj[i].push_back(v);
        }
    }

    queue<int> q;
    for (int i = 1; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    if (q.size() != 1) {
        cout << "0\n";
        return 0;
    }

    while (q.size() != 0) {
        if (q.size() != 1) {
            cout << "0\n";
            return 0;
        }
        int val = q.front();
        q.pop();
        for (int x : adj[val]) {
            in[x]--;
            if (in[x] == 0) q.push(x);
        }
    }

    cout << 1 << endl;
}


