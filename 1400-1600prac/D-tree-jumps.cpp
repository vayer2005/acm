#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    int val;
    for(int i = 2; i < n+1; i++) {
        cin >> val;
        mp[val].push_back(i);
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