#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    string s;
    cin >> s;

    int lastInd = -1;
    for(int i = 0; i < s.size()-1;i++) {
        if (s[i] == s[i+1]) {
            lastInd = i;
        }
    }

    if (lastInd == -1) {
        cout << s.size() << endl;
    } else {
        cout << 1 << endl;
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}