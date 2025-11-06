#include <bits/stdc++.h>
#define int long long

using namespace std;

tuple<int, int, int> extended_euclid(int a, int b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [d, x1, y1] = extended_euclid(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;
    return {d, x, y};
}

// Solves x ≡ a (mod m), x ≡ b (mod n)
// Returns {remainder, modulus} or {-1, -1} if no solution exists
pair<int, int> crt(pair<int,int> p1, pair<int,int> p2) {
    int a = p1.first, m = p1.second;
    int b = p2.first, n = p2.second;

    if (a < 0 || b < 0) return {-1, -1};

    auto [d, x, y] = extended_euclid(m, n);
    if ((a - b) % d != 0) return {-1, -1}; // No solution

    int l = (a - b) / d;
    int ret_mod = m / d * n;

    l %= ret_mod;
    int ret = b + n * l * y;
    ret = ((ret % ret_mod) + ret_mod) % ret_mod; // Ensure non-negative

    return {ret, ret_mod};
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int currans = -1; 
    int currmod = -1;

    vector<int> seen;

    for (int i = 0; i < n; i++) {
        //cout << currans << " " << currmod << endl;
        int ch = s[i] - 'A';
        int rem = ch;
        int md = n-i;
        for (int j : seen) {
            if (j < ch) {
                rem--;
            }
        }

        if (currans == -1) {
            currans = rem;
            currmod = md;
        } else {
            auto check = crt({currans, currmod}, {rem, md});
            if (check.first == -1) {
                cout << "NO\n";
                return;
            }
            currans = check.first;
            currmod = check.second;
        }
        seen.push_back(ch);
    }

    cout << "YES\n";
    cout << currans << endl;
    
}

signed main() {
  solve();
}

