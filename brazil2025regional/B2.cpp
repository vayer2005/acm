#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = 3.141592653589793;

int has[101][1000001];
vector<int> adj[101];
int link[101][101];
vector<int> film[101];
int bfs[101][101];
int par[101][101]; 
int n, m;

int cmp(int i, int j) {
    if (adj[i].size() > adj[j].size()) swap(i, j);

    for (int x : adj[i]) {
        if (has[j][x]) return x;
    }
    return -1;
}

void solve(int a, int b) {
    for (int i = 0; i < n; i++) {
            if (!has[i][a]) continue;

            for (int j = 0; j < n; j++) {
                if (bfs[i][j] && has[j][b]) {
                    //found a solution
                    vector<int> sol;
                    sol.push_back(b);
                    int mov = j;
                    while (true) {
                        sol.push_back(mov);
                        if (mov == i) break;
                        int nxt = par[i][mov];
                        sol.push_back(link[mov][nxt]);
                        mov = nxt;
                    }
                    sol.push_back(a);

                    reverse(sol.begin(), sol.end());

                    cout << (sol.size()/2) + 1 << endl;

                    for (int x : sol) {
                        cout << x+1 << " "; 
                    }
                    cout << endl;
                    return;
                }
            }
        }
        cout << "-1\n";
        return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(bfs, 0, sizeof(bfs));
    cin >> n >> m;
    memset(link, -1, sizeof(link));
    memset(has, 0, sizeof(has));
    memset(par, -1, sizeof(par));

    int num, x;
    for (int i = 0; i < n; i++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> x;
            x--;
            adj[i].push_back(x);
            has[i][x] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            
            int edge = cmp(i,j);
            if (edge != -1) {
                link[i][j] = edge;
                link[j][i] = edge;
                film[i].push_back(j);
                film[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bfs[i][i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int y = 0; y < n; y++)
            {
                if (!bfs[i][y] && link[x][y] != -1)
                {
                    bfs[i][y] = 1;
                    par[i][y] = x;
                    q.push(y);
                }
            }
        }
    }

    int qu;
    cin >> qu;
    int a, b;

    while (qu--) {
        cin >> a >> b;
        a--;b--;
        solve(a,b);
    }
}