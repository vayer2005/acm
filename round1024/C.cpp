#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

int dx[] = {0, 1, 0, -1}; // y movement
int dy[] = {1, 0, -1, 0}; // x movement

void fillSpiralFromCenter(int n, vector<vector<int>>& matrix) {
    int x = (n / 2);
    int y = (n / 2);
    if (n % 2 == 0)  {
        x--; y--;
    }

    int val = 0;
    matrix[x][y] = val++;

    int steps = 1;
    while (val < n * n) {
        for (int dir = 0; dir < 4; dir++) {
            int stepCount = (dir < 2) ? steps : steps + 1;
            for (int i = 0; i < stepCount; i++) {
                x += dx[dir];
                y += dy[dir];
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    matrix[x][y] = val++;
                }
                if (val >= n * n) return;
            }
        }
        steps += 2;
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, -1));

    fillSpiralFromCenter(n, matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}