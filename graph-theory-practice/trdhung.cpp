#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define bit(n) (1LL << (n))
#define getbit(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>
#define ALL(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound
#define rep(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int oo = 1e9;
const long long ooo = 1e18;
const double pi = acos(-1);
template<typename T1, typename T2> bool mini(T1 &a, T2 b) {if(a
> b) a = b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b) {if(a
< b) a = b; else return 0; return 1;}
typedef long long ll;
typedef vector <int> vi;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().
count());
long long rand(long long l, long long r) {
return l + rd() % (r - l + 1);
}


int ng[50][50], used[50][50];
vector<vi> W(16, vi(16,1<<20));
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int Bt, Xt, n, m;
char g[50][50];


void bfs(int x, int y) {
    memset(used, 0, sizeof(used));
    int i, tx, ty;
    queue<int> X, Y;
    X.push(x), Y.push(y);
    used[x][y] = 1; 
    while(!X.empty()) {
        x = X.front(), X.pop();
        y = Y.front(), Y.pop();
        if(g[x][y] == 'X')
            W[Bt+1][ng[x][y]+1] = used[x][y]-1; 
        for(i = 0; i < 4; i++) {
            tx = x+dx[i], ty = y+dy[i];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m)
                continue;
            if(g[tx][ty] == '#')
                continue;
            if(used[tx][ty] == 0) {
                used[tx][ty] = used[x][y]+1;
                X.push(tx);
                Y.push(ty);
            }
        }
    }
}



int hungarian(vector<vi> &cost, int n) {
    vector<int> u(n+1), v(n+1), p(n+1), way(n+1);
    for(int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n+1, 1<<20);
        vector<bool> used(n+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = 1<<20, j1;
            for(int j = 1; j <= n; j++) {
                if(!used[j]) {
                    int cur = cost[i0][j] - u[i0] - v[j];
                    if(cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if(minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for(int j = 0; j <= n; j++) {
                if(used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while(p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    int ans = 0;
    for(int j = 1; j <= n; j++) {
        ans += cost[p[j]][j];
    }
    return ans;
}






int main() {
    int t, i, j, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
            scanf("%s", g[i]);

        Bt = 0, Xt = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                if(g[i][j] == 'X')
                    ng[i][j] = Xt++;

        // Initialize W with unreachable value
        for(i = 0; i < 16; i++)
            for(j = 0; j < 16; j++)
                W[i][j] = 1<<20;

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                if(g[i][j] == 'B') {
                    bfs(i, j);
                    Bt++;
                }
            }
        }


        cout << hungarian(W, Bt) << endl;
    }
    return 0;
}
