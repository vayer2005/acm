#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; int m1; int m2;

    cin >> n >> m1 >> m2;
    unordered_map<int, unordered_set<int>> u1;
    unordered_map<int, unordered_set<int>> u2;

    int key; int val;
    for (int i = 0; i < m1; i++) {
        cin >> key >> val;
        if (u1.find(key) == u1.end()) {
            unordered_set<int> vals = {val};
            u1[key] = vals;
        } else {
            unordered_set<int> vals = u1[key];
            vals.insert(val);
            u1[key] = vals;
        }
    }

    for (int i = 0; i < m2; i++) {
        cin >> key >> val;
        if (u2.find(key) == u2.end()) {
            unordered_set<int> vals = {val};
            u2[key] = vals;
        } else {
            unordered_set<int> vals = u2[key];
            vals.insert(val);
            u2[key] = vals;
        }
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
        unordered_set<int> v1;
        unordered_set<int> v2;
        if (u1.find(i) == u1.end()) {
            v1 = {};
        } else {
            v1 = u1[i];
        }
        if (u2.find(i) == u2.end()) {
            v2 = {};
        } else {
            v2 = u2[i];
        }
        unordered_set<int>::iterator itr;
        for (itr = v1.begin(); itr != v1.end(); itr++) {
            if (v2.find(*itr) == v2.end()) {
                total += 1;
            }
        }

        for (itr = v2.begin(); itr != v2.end(); itr++) {
            if (v1.find(*itr) == v1.end()) {
                total += 1;
            }
        }
    }

    cout << total << endl;


}
    

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}