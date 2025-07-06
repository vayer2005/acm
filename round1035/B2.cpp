#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

bool canBuild(const vector<int64>& b, int64 x) {
    const int n = (int)b.size();
    vector<int64> prev;
    prev.reserve(2);
    // first element: two possibilities
    prev.push_back(b[0]);
    if (b[0] % x == 0) prev.push_back(b[0] / x);

    // remove duplicates
    if (prev.size() == 2 && prev[0] == prev[1]) prev.pop_back();

    for (int i = 1; i < n; ++i) {
        vector<int64> cur;
        cur.reserve(2);

        // possible original values for this index
        int64 v1 = b[i];
        int64 v2 = (b[i] % x == 0 ? b[i] / x : -1);

        for (int64 prevVal : prev) {
            if (v1 % prevVal == 0) cur.push_back(v1);
            if (v2 != -1 && v2 % prevVal == 0) cur.push_back(v2);
        }
        // deduplicate
        if (cur.size() == 2 && cur[0] == cur[1]) cur.pop_back();
        if (cur.empty()) return false;
        prev.swap(cur);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Collect candidate x values from every adjacent pair where divisibility fails
        vector<int64> candidates;
        candidates.reserve(2 * (n - 1));
        for (int i = 0; i + 1 < n; ++i) {
            if (b[i + 1] % b[i] == 0) continue; // already divisible, gives no information
            int64 g = std::gcd(b[i], b[i + 1]);
            int64 u = b[i] / g;
            int64 v = b[i + 1] / g;
            if (u > 1) candidates.push_back(u);
            if (v > 1) candidates.push_back(v);
        }

        if (candidates.empty()) {
            cout << 1 << '\n'; // array is already beautiful
            continue;
        }

        // Deduplicate and try candidates (larger first heuristic)
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        sort(candidates.rbegin(), candidates.rend());

        int64 answer = 1;
        for (int64 x : candidates) {
            if (canBuild(b, x)) {
                answer = x;
                break;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}