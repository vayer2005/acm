#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> vals;
    vals.push_back(s[0]);

    for(int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            vals.push_back(s[i]);
        }
    }

    int total = 0;
    bool seen1 = false;
    for(int i = 0; i < vals.size(); i++) {
        if (vals[i] == '1') {
            seen1 =true;
            total += 1;
        } else if (vals[i] == '0' && seen1){
            total += 1;
        }
    }

    cout << total << endl;


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