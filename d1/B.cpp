#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> vals;

bool customComparison(int a, int b) {
    if (vals[a-1][b-1] == '1') {
        return a < b;
    }
    return b < a;
}

void solve() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vals.push_back(s);
    }

    vector<int> sol(n,0);

    for (int i = 1; i <= n; i++) {
        sol[i-1] = i;
    }

    sort(sol.begin(), sol.end(), customComparison);

    for (int i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;

    vals.clear();
}



int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}