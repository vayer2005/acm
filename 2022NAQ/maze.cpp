#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

vector<string> v;
int n; int m; // rows, col
vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int dfs(int i, int j) {
    if (v[i][j] == '.') {
        v[i][j] = 'X';
        for (auto d : dir) {
            int nx = i + d[0];
            int ny = j + d[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (v[nx][ny] == '.' || v[nx][ny] == ' ' )) {
                dfs(nx, ny);
            }
        }
        return 1;
    } else if (v[i][j] == ' ') {
        v[i][j] = 'X';
        int ret = 0;
        for (auto d : dir) {
            int nx = i + d[0];
            int ny = j + d[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (v[nx][ny] == '.' || v[nx][ny] == ' ' )) {
                ret = dfs(nx, ny) + ret;
            }
        }
        return ret;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    cin.ignore(); // Ignore the newline after n and m

    v.resize(n); // Initialize vector with correct size
    for(int i = 0; i < n; i++) {
        getline(cin, v[i]);
    }

    int doors = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (v[i][j] != 'X' && v[i][j] != '.' && v[i][j] != ' ') {
                int ret = 0;
                for (auto d : dir) {
                    int nx = i + d[0];
                    int ny = j + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && (v[nx][ny] == '.' || v[nx][ny] == ' ' )) {
                        ret += dfs(nx,ny);
                    }
                }
                if (ret) {
                    doors++;
                }
            }
        }
    }

    int unr = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (v[i][j] == '.') {
                unr++;
            }
        }
    }
    
    cout << doors << " " << unr << endl;
}