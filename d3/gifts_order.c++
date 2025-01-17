#include <bits/stdc++.h>

using i64 = long long;

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;

    SegmentTree() : n(0) {}

    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }

    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }

    void init(int n_, Info v_ = Info()) {
        init(std::vector<Info>(n_, v_));
    }

    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        int sz = (1 << (std::__lg(n - 1) + 1));
        info.assign(sz * 2, Info());
        std::function<void(int, int, int)> build = [&](int v, int l, int r) {
            if (l == r) {
                info[v] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(v + v, l, m);
            build(v + v + 1, m + 1, r);
            info[v] = info[v + v] + info[v + v + 1];
        };
        build(1, 0, n - 1);
    }

    Info rangeQuery(int v, int l, int r, int tl, int tr) {
        if (r < tl || l > tr) {
            return Info();
        }
        if (l >= tl && r <= tr) {
            return info[v];
        }
        int m = (l + r) / 2;
        return rangeQuery(v + v, l, m, tl, tr) + rangeQuery(v + v + 1, m + 1, r, tl, tr);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }

    void modify(int v, int l, int r, int i, const Info &x) {
        if (l == r) {
            info[v] = x;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            modify(v + v, l, m, i, x);
        } else {
            modify(v + v + 1, m + 1, r, i, x);
        }
        info[v] = info[v + v] + info[v + v + 1];
    }

    void modify(int i, const Info &x) {
        modify(1, 0, n - 1, i, x);
    }

    Info query(int v, int l, int r, int i) {
        if (l == r) {
            return info[v];
        }
        int m = (l + r) / 2;
        if (i <= m) {
            return query(v + v, l, m, i);
        } else {
            return query(v + v + 1, m + 1, r, i);
        }
    }

    Info query(int i) {
        return query(1, 0, n - 1, i);
    }
};

const int INF = 1E9;

struct Info {
    int min1, min2, max1, max2, ans1, ans2;

    Info() : min1(INF), min2(INF), max1(-INF), max2(-INF), ans1(0), ans2(0) {}

    Info(std::pair<int, int> x) : min1(x.first), min2(x.second), max1(x.first), max2(x.second), ans1(0), ans2(0) {}
};

Info operator+(const Info &a, const Info &b) {
    Info res;
    res.min1 = std::min(a.min1, b.min1);
    res.min2 = std::min(a.min2, b.min2);
    res.max1 = std::max(a.max1, b.max1);
    res.max2 = std::max(a.max2, b.max2);
    res.ans1 = std::max({a.ans1, b.ans1, b.max1 - a.min1});
    res.ans2 = std::max({a.ans2, b.ans2, a.max2 - b.min2});
    return res;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::vector<std::pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        t[i] = {a[i] - i, a[i] + i - n + 1};
    }
    SegmentTree<Info> st(t);
    auto query = [&]() {
        return std::max(st.info[1].ans1, st.info[1].ans2);
    };
    std::cout << query() << "\n";
    for (int i = 0; i < q; i++) {
        int p, x;
        std::cin >> p >> x;
        p--;
        t[p] = {x - p, x + p - n + 1};
        st.modify(p, t[p]);
        std::cout << query() << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }
}