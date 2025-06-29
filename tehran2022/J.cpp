#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, j;
    cin >> n >> i >> j;
    int N = 2 * n;
    i--, j--;
    vector<int> dist(N, -1);
    queue<int> q;
    dist[i] = 0;
    q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (x == j) break;
        int y = (x % 2 == 0) ? x + 1 : x - 1;
        if (dist[y] == -1) {
            dist[y] = dist[x] + 1;
            q.push(y);
        }
        int z;
        if (x < n) z = 2 * x;
        else z = 2 * (x - n) + 1;
        if (dist[z] == -1) {
            dist[z] = dist[x] + 1;
            q.push(z);
        }
    }
    cout << dist[j] << endl;
}