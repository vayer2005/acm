#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int m; int k;
    cin >> n >> m >> k;


    int val = 1;

    if (m % k == 0) {
        for (int i = 0; i < n; i++) {
            if (i%2 == 1) {
                val = 2;
            } else {
                val = 1;
            }
            for(int j = 0; j < m; j++) {
                cout << val << " ";
                val = (val+1)%(k+1);
                if (val == 0) {
                    val++;
                }
            }
            cout << endl;
        }

    } else {
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << val << " ";
                val = (val+1)%(k+1);
                if (val == 0) {
                    val++;
                }
            }
            cout << endl;
        }
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