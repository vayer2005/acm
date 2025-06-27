#include <bits/stdc++.h>

using namespace std;
#define int long long


vector<int> dsu(300001, -1);
vector<int> cap(300001, -1);
vector<int> filled(300001, 0);

int fill(int val, int left) {
    if (val == -1) {
        return -1;
    }
    if (filled[val] + left > cap[val]) {
        int nleft = left - (cap[val] - filled[val]);
        filled[val] = cap[val];
        dsu[val] = fill(dsu[val], nleft);
        return dsu[val];
    } else {
        filled[val] += left;
        return val;
    }
}


signed main() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> cap[i];
    }

    stack<pair<int,int>> vals;
    for (int i = n; i >= 1; i--) {
        int curr = cap[i];
        while (!vals.empty() && vals.top().first < curr) {
            vals.pop();
        }
        if (!vals.empty()) {
            dsu[i] = vals.top().second;
        }
        vals.push({curr, i});
    }

    char c; int a, b;
    while (q--) {
        cin >> c;
        if (c == '+') {
            cin >> a >> b;
            fill(a, b);
        } else {
            cin >> a;
            cout << filled[a] << endl;
        }
    }


}