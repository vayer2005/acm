#include <bits/stdc++.h>

# define int long long

using namespace std;

const int MAXN = 100001;

int n;
int c[MAXN];
int cnt[MAXN];
vector<pair<int, int>> g[MAXN];

map<int, int> cnv[MAXN];
int f[MAXN];
int s[MAXN];

void merge(int v, int u) { // merge u into v
    if (cnv[v].size() < cnv[u].size()) {
        cnv[v].swap(cnv[u]);
        swap(f[v], f[u]);
    }

    for (auto [x, cnx]: cnv[u]) {
        int av = cnv[v][x] * (cnt[x] - cnv[v][x]);
        f[v] -= av;

        cnv[v][x] += cnx;

        av = cnv[v][x] * (cnt[x] - cnv[v][x]);
        f[v] += av;

        if (av == 0) { // Not necessary
            cnv[v].erase(x);
        }
    }

    cnv[u].clear();
    //f[u] = 0;
    //cnt[u] = 0;
}

void dfs(int v, int par = -1) {
    cnv[v][c[v]] = 1;
    f[v] = cnt[c[v]] - 1;

    for (auto [u, i]: g[v]) {
        if (u != par) {
            dfs(u, v);
            s[i] = f[u];
            merge(v, u);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        cnt[c[i]] ++;
    }

    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v --, u --;
        g[v].emplace_back(u, i);
        g[u].emplace_back(v, i);
    }

    dfs(0);

    for (int i = 0; i < n - 1; i ++)
        cout << s[i] << endl;

    return 0;
}