#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; cin >>n;

    string s; cin >> s;

    int l=0; int r = n-1;
    int ops = 0;

    if (n % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> solution;
    while (l < r) {
        //cout << s << endl;
        if (ops > 300) {
            cout << -1 << endl;
            return;
        }
        if (s[l] != s[r]) {
            l+=1; r-=1;
            continue;
        }
        if (s[l] == '0') {
            s = s.substr(0,r+1) + "01"+ s.substr(r+1, n-r-1);
            solution.push_back(r+1);
            r += 2;
            ops +=1;
            n+=2;
        } else  {
            s = s.substr(0, l) + "01" + s.substr(l,n-l);
            solution.push_back(l);
            ops += 1;
            r+=2;
            n+=2;
        }
    }
    if (ops > 300) {
        cout << -1 << endl;
        return;
    }
    cout << ops << endl;
    for(int i = 0;i < ops;i++) {
        cout << solution[i] << " ";
    }
    cout << endl;

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