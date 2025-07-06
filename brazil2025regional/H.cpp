#include <bits/stdc++.h>

using namespace std;
#define int long long

const double EPS = 1e-9;
const double PI = 3.141592653589793;

vector<string> m;
vector<string> n;

void dfs1(string val, int ind) {
    for (int i = ind; i < val.size(); i++) {
        if (val[i] == '*') {
            string op1 = val.substr(0, i) + '0' + val.substr(i+1, val.size()-i-1);
            string op2 = val.substr(0, i) + '1' + val.substr(i+1, val.size()-i-1);
            dfs1(op1, i+1);
            dfs1(op2, i+1);
            return;
        }
    }
    m.push_back(val);
}

void dfs2(string val, int ind) {
    for (int i = ind; i < val.size(); i++) {
        if (val[i] == '*') {
            string op1 = val.substr(0, i) + '0' + val.substr(i+1, val.size()-i-1);
            string op2 = val.substr(0, i) + '1' + val.substr(i+1, val.size()-i-1);
            dfs2(op1, i+1);
            dfs2(op2, i+1);
            return;
        }
    }
    n.push_back(val);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1; string s2;
    cin >> s1 >> s2;

    dfs1(s1,0);
    dfs2(s2,0);

    for (string x : n) {
        int v = 0;
        for (char c : x) {
            v = v*2+(c-'0');
        }
        for (string y : m) {
            int res = 0;
            for (char c : y) {
                res = ((res * 2)%v + (c-'0'))%v;
            }
            if (res % v == 0) {
                cout << y << endl;
                return 0;
            }
        }
    }
}