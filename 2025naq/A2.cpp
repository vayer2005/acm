#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int n, d, w;

    cin >> n >> d >> w;

    string tot = "";

    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i % 2 == 1) {
            reverse(s.begin(), s.end());
        }

        tot += s;
    }
    

    //cout << tot << endl;
    int idx = 0;
    int ans = 0;
    while (idx < tot.size()) {
        //cout << idx << endl;
        if (idx + w - 1 >= tot.size()) {
            ans++;
            break;
        } else {
            //cout << "H\n";
            if (idx + w - 1 == tot.size()-1) {
                ans++;
                break;
            }
            if (tot[idx + w-1] == '.') {
                //cout << "H\n";
                ans++;
                idx = idx + w;
            } else if (idx + w < tot.size() && tot[idx + w] == '.') {
                //cout << "H1\n";
                ans++;
                idx = idx + w + 1;
            } else {
                int nid = idx + w;
                while (tot[nid] != '.') {
                    nid--;
                }
                ans++;
                idx = nid + 1;
            }
        }
    }

    cout << ans << endl;




}