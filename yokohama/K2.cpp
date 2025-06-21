#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> masks(n);
    int all_ones = (1 << m) - 1;
    vector<int> mask_to_slots[1<<m];
    vector<int> unique_masks;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < m; ++j)
            if (s[j] == 'Y') mask |= (1 << j);
        masks[i] = mask;
        if (mask_to_slots[mask].empty()) unique_masks.push_back(mask);
        if (mask_to_slots[mask].size() < 2)
            mask_to_slots[mask].push_back(i);
    }

    int best_both = -1, best_i = n, best_j = n;
    set<int>seen;
    int sz = unique_masks.size();
    for (int idx1 = 0; idx1 < sz; ++idx1) {
        int mask1 = unique_masks[idx1];
        if (seen.find(mask1) != seen.end()) continue;
        seen.insert(mask1);
        for (int idx2 = idx1; idx2 < sz; ++idx2) {
            int mask2 = unique_masks[idx2];
            if ((mask1 | mask2) == all_ones) {
                for (int i1 : mask_to_slots[mask1]) {
                    for (int i2 : mask_to_slots[mask2]) {
                        if (i1 == i2) continue;
                        int i = min(i1, i2), j = max(i1, i2);
                        int both = __builtin_popcount(mask1 & mask2);
                        if (both > best_both ||
                            (both == best_both && (i < best_i || (i == best_i && j < best_j)))) {
                            best_both = both;
                            best_i = i;
                            best_j = j;
                        }
                    }
                }
            }
        }
    }

    if (best_both == -1) {
        cout << "No\n";
    } else {
        cout << best_i + 1 << " " << best_j + 1 << "\n";
    }
}