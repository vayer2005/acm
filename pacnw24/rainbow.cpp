#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Rainbow Bowl Ranges
// ------------------------------------------------------------
// For every colour with c < n there is a single contiguous GAP of
// length g = n - c (the bowls that colour does NOT occupy).
// Rainbow bowls are those that lie in NONE of the gaps, i.e. in the
// complement of the union of gaps.  If the union of gaps splits into K
// connected components on the circle, then the rainbow area also splits
// into exactly K components (they appear between the gap components).
// So maximising the number of rainbow ranges is equivalent to
// maximising how many connected components the union of gaps can have.
//
// Key lemma: it is always optimal to place at most one gap per desired
// component.  Additional gaps can be stacked on existing components
// without increasing their total length.  Hence, to create exactly K
// components we only need to keep *K* gaps separate; the other gaps can
// overlap arbitrarily.
//
// To be feasible those K gaps must fit on the circle together with at
// least one rainbow bowl between consecutive components:
//     (g1 + g2 + ... + gK)   +   K   <= n         (1)
// where g1..gK are the lengths of the chosen gaps.
// The left-hand side is minimised by taking the *K smallest* gaps.  So
// the maximal K is the largest prefix of the sorted (ascending) gap list
// that satisfies (1).
// ------------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; // number of bowls, up to 1e9
    int m;       // number of colours, up to 1e5
    if (!(cin >> n >> m)) return 0;

    vector<long long> gaps; // collect g = n - c for each colour with c < n
    gaps.reserve(m);

    for (int i = 0; i < m; ++i) {
        long long c; cin >> c;
        if (c < n) gaps.push_back(n - c);
    }

    // If every colour covers the whole circle there is no gap at all, so
    // the entire circle is a single rainbow range.
    if (gaps.empty()) {
        cout << 1 << '\n';
        return 0;
    }

    sort(gaps.begin(), gaps.end(), greater<>()); // descending (largest first)

    long long prefixSum = 0; // Σ g_i over processed gaps
    long long best = 0;      // best K found so far

    for (size_t k = 1; k <= gaps.size(); ++k) {
        prefixSum += gaps[k - 1]; // add k-th largest gap
        // Condition (1)
        if (prefixSum + static_cast<long long>(k) <= n) {
            best = k; // feasible, try to enlarge K
        } else {
            break;    // larger k will only make LHS bigger
        }
    }

    cout << best << '\n';
    return 0;
}