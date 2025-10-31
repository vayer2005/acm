// Correct solution using binary search on the robot size.
// For a candidate side s, we:
// 1) Compute all valid top-left placements (s x s contains no obstacle) using a
//    precomputed 2D prefix sum of obstacles.
// 2) Check these placements form one connected component (4-neighborhood).
// 3) Using a 2D difference array, verify the union of all valid placements
//    covers every unobstructed cell.

#include <bits/stdc++.h>

using namespace std;

static inline int id2d(int r, int c, int W) { return r * W + c; }

int n, m, k;

// Check whether a square robot of side s can clean the entire room
// given the prefix sums 'ps' and the obstacle bitmap 'obs'.
static bool canClean(int s, const vector<int> &ps, const vector<unsigned char> &obs) {
    if (s <= 0) return false;
    if (s > n || s > m) return false;

    const int Wps = m + 1;          // width for prefix sums (0..m)
    const int N = n - s + 1;        // valid top-left rows
    const int M = m - s + 1;        // valid top-left cols

    // Build the grid of valid top-left placements
    vector<unsigned char> valid((long long)N * (long long)M, 0);
    long long totalValid = 0;

    auto rectSum = [&](int r1, int c1, int r2, int c2) -> int { // all inclusive, 1-based
        return ps[id2d(r2, c2, Wps)] - ps[id2d(r1 - 1, c2, Wps)]
             - ps[id2d(r2, c1 - 1, Wps)] + ps[id2d(r1 - 1, c1 - 1, Wps)];
    };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int sum = rectSum(i, j, i + s - 1, j + s - 1);
            unsigned char ok = (sum == 0);
            valid[(long long)(i - 1) * M + (j - 1)] = ok;
            totalValid += ok;
        }
    }

    // If there are no valid placements but there exists any free cell, impossible.
    if (totalValid == 0) return false;

    // Connectivity check of 'valid' grid (4-neighborhood)
    long long visited = 0;
    queue<int> q;
    int start = -1;
    for (long long idx = 0; idx < (long long)N * M; idx++) {
        if (valid[idx]) { start = (int)idx; break; }
    }
    if (start == -1) return false;

    q.push(start);
    valid[start] = 2; // mark visited
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int r = cur / M; // 0-based in [0..N-1]
        int c = cur % M; // 0-based in [0..M-1]
        visited++;
        // neighbors: up, down, left, right
        if (r > 0) {
            int v = cur - M; if (valid[v] == 1) { valid[v] = 2; q.push(v); }
        }
        if (r + 1 < N) {
            int v = cur + M; if (valid[v] == 1) { valid[v] = 2; q.push(v); }
        }
        if (c > 0) {
            int v = cur - 1; if (valid[v] == 1) { valid[v] = 2; q.push(v); }
        }
        if (c + 1 < M) {
            int v = cur + 1; if (valid[v] == 1) { valid[v] = 2; q.push(v); }
        }
    }
    if (visited != totalValid) return false; // not connected

    // Coverage check: union of all valid s x s placements must cover every free cell
    const int Wd = m + 2; // for difference array (1..n,1..m) with +1 padding
    vector<int> diff((long long)(n + 2) * (m + 2), 0);

    for (int i = 1; i <= N; i++) {
        long long base = (long long)(i - 1) * M;
        for (int j = 1; j <= M; j++) {
            if (valid[base + (j - 1)] != 2) continue; // only visited-valid cells
            // valid==2 are exactly the valid placements (we visited all of them)
            int r1 = i, c1 = j;
            int r2 = i + s - 1, c2 = j + s - 1;
            diff[id2d(r1, c1, Wd)] += 1;
            diff[id2d(r2 + 1, c1, Wd)] -= 1;
            diff[id2d(r1, c2 + 1, Wd)] -= 1;
            diff[id2d(r2 + 1, c2 + 1, Wd)] += 1;
        }
    }

    // Prefix of diff to get coverage counts
    for (int i = 1; i <= n; i++) {
        int run = 0;
        for (int j = 1; j <= m; j++) {
            run += diff[id2d(i, j, Wd)];
            diff[id2d(i, j, Wd)] = run + diff[id2d(i - 1, j, Wd)];
        }
    }

    // Verify every non-obstructed cell is covered at least once
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (obs[id2d(i, j, m + 1)] == 0) {
                if (diff[id2d(i, j, Wd)] <= 0) return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    // Obstacle bitmap (1..n, 1..m), we store at width (m+1) for 1-based addressing
    const int W = m + 1;
    vector<unsigned char> obs((long long)(n + 1) * (m + 1), 0);
    for (int t = 0; t < k; t++) {
        int r, c; cin >> r >> c;
        obs[id2d(r, c, W)] = 1;
    }

    // Build 2D prefix sums of obstacles into 'ps' (0..n, 0..m)
    vector<int> ps((long long)(n + 1) * (m + 1), 0);
    for (int i = 1; i <= n; i++) {
        int row = 0;
        for (int j = 1; j <= m; j++) {
            row += (obs[id2d(i, j, W)] ? 1 : 0);
            ps[id2d(i, j, W)] = ps[id2d(i - 1, j, W)] + row;
        }
    }

    int lo = 1, hi = min(n, m), ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canClean(mid, ps, obs)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}