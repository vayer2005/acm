// Competitive programming implementation for:
// Another Substring Query Problem
// Approach:
// 1) Build suffix array for s.
// 2) Build a persistent segment tree (Chairman Tree) over the array A = SA,
//    where A[i] is the starting index of the i-th lexicographically smallest suffix.
//    This supports querying the k-th smallest value in any subarray A[L..R].
// 3) For each query (t, k):
//    - Find the suffix-array interval [L, R) of suffixes starting with t via two
//      lower_bounds on SA using a comparator that compares only |t| characters.
//    - If R-L < k -> print -1
//      Else, answer is kth(root[R], root[L], 0..n-1, k) + 1 (1-based).

#include <bits/stdc++.h>
using namespace std;

// -------------------- Suffix Array (doubling) --------------------
static vector<int> build_suffix_array(const string &s_in) {
	string s = s_in;
	s.push_back('\0'); // sentinel smaller than 'a'
	int n = (int)s.size();
	vector<int> p(n), c(n);
	{
		vector<pair<char,int>> a(n);
		for (int i = 0; i < n; ++i) a[i] = {s[i], i};
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) p[i] = a[i].second;
		c[p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			c[p[i]] = c[p[i-1]] + (a[i].first != a[i-1].first);
		}
	}
	int k = 0;
	vector<int> p_new(n), c_new(n);
	while ((1 << k) < n) {
		for (int i = 0; i < n; ++i) {
			p[i] = (p[i] - (1 << k) + n) % n;
		}
		int classes = *max_element(c.begin(), c.end()) + 1;
		vector<int> cnt(classes, 0), pos(classes, 0);
		for (int i = 0; i < n; ++i) cnt[c[i]]++;
		for (int i = 1; i < classes; ++i) pos[i] = pos[i-1] + cnt[i-1];
		for (int i = 0; i < n; ++i) {
			int cl = c[p[i]];
			p_new[pos[cl]++] = p[i];
		}
		p.swap(p_new);
		c_new[p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
			pair<int,int> now  = {c[p[i]],   c[(p[i]   + (1 << k)) % n]};
			c_new[p[i]] = c_new[p[i-1]] + (now != prev);
		}
		c.swap(c_new);
		++k;
	}
	// Remove the sentinel position
	vector<int> sa;
	sa.reserve(n - 1);
	for (int idx : p) if (idx != n - 1) sa.push_back(idx);
	return sa; // size = |s_in|
}

// Compare suffix s[pos..] with pattern t, but only up to |t| characters.
// Return true if suffix < t in that truncated lexicographic order.
static inline bool suffix_less_than_pattern(const string &s, int pos, const string &t) {
	int n = (int)s.size();
	int m = (int)t.size();
	for (int i = 0; i < m; ++i) {
		if (pos + i >= n) return true; // suffix ended before t -> suffix is smaller
		char a = s[pos + i];
		char b = t[i];
		if (a != b) return a < b;
	}
	return false; // equal for first |t| chars -> not strictly less
}

// lower_bound on SA for pattern t under the comparator above
static int sa_lower_bound(const vector<int> &sa, const string &s, const string &t) {
	int l = 0, r = (int)sa.size();
	while (l < r) {
		int mid = (l + r) >> 1;
		if (suffix_less_than_pattern(s, sa[mid], t)) l = mid + 1; else r = mid;
	}
	return l; // first index where suffix >= t
}

// -------------------- Persistent Segment Tree (range k-th) --------------------
struct PersistentSegTree {
	struct Node { int left, right, cnt; };
	vector<Node> tree; // 0 is the null node
	vector<int> roots; // prefix roots: roots[i] after inserting first i values
	int n; // domain [0..n-1]

	PersistentSegTree() : n(0) {}
	explicit PersistentSegTree(int nDomain) : n(nDomain) {
		tree.reserve(1 + nDomain * 20);
		tree.push_back({0,0,0}); // null node
	}

	int new_node(int from) {
		tree.push_back(tree[from]);
		return (int)tree.size() - 1;
	}

	int update(int prev, int l, int r, int pos) {
		int cur = new_node(prev);
		++tree[cur].cnt;
		if (l == r) return cur;
		int mid = (l + r) >> 1;
		if (pos <= mid) {
			int nxt = update(tree[cur].left, l, mid, pos);
			tree[cur].left = nxt;
		} else {
			int nxt = update(tree[cur].right, mid + 1, r, pos);
			tree[cur].right = nxt;
		}
		return cur;
	}

	// Return k-th (1-based) smallest in multiset represented by rootR - rootL
	int kth(int rootR, int rootL, int l, int r, int k) const {
		if (l == r) return l;
		int mid = (l + r) >> 1;
		int leftCount = tree[tree[rootR].left].cnt - tree[tree[rootL].left].cnt;
		if (k <= leftCount) {
			return kth(tree[rootR].left, tree[rootL].left, l, mid, k);
		}
		return kth(tree[rootR].right, tree[rootL].right, mid + 1, r, k - leftCount);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	if (!(cin >> s)) return 0;
	int n = (int)s.size();

	// Build SA and PST over SA values
	vector<int> sa = build_suffix_array(s);
	PersistentSegTree pst(n);
	vector<int> roots(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		roots[i + 1] = pst.update(roots[i], 0, n - 1, sa[i]);
	}

	int q; cin >> q;
	while (q--) {
		string t; long long k; // k can be up to |s|
		cin >> t >> k;
		int L = sa_lower_bound(sa, s, t);
		string tNext = t; tNext.push_back('{');
		int R = sa_lower_bound(sa, s, tNext);
		int occ = R - L;
		if (occ < k || occ <= 0) {
			cout << -1 << '\n';
			continue;
		}
		int pos = pst.kth(roots[R], roots[L], 0, n - 1, (int)k);
		cout << (pos + 1) << '\n';
	}
	return 0;
}


