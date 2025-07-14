#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;              
    if (!(cin >> n)) return 0;

    const int half = n / 2;
    vector<int> a(half), b(half);
    for (int &x : a) cin >> x;       
    for (int &x : b) cin >> x;

    vector<int> bit(n + 1, 0);        
    auto add = [&](int idx, int delta) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += delta;
    };
    auto sum = [&](int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    };
    for (int i = 1; i <= n; ++i) add(i, 1);

    auto kth = [&](int k) {
        int idx = 0;
        int step = 1;
        while (step <= n) step <<= 1;
        for (; step; step >>= 1) {
            int next = idx + step;
            if (next <= n && bit[next] < k) {
                k -= bit[next];
                idx = next;
            }
        }
        return idx + 1;
    };


    vector<int> asol; asol.reserve(half);
    vector<int> bsol; bsol.reserve(half);

    for (int i = 0; i < half; ++i) {
        int aval = kth(a[i]); 
        asol.push_back(aval);
        add(aval, -1);      

        int bval = kth(b[i]);   
        bsol.push_back(bval);
        add(bval, -1);        
    }

    for (int i = 0; i < half; ++i) {
        cout << asol[i] << (i + 1 == half ? '\n' : ' ');
    }
    for (int i = 0; i < half; ++i) {
        cout << bsol[i] << (i + 1 == half ? '\n' : ' ');
    }

    return 0;
}