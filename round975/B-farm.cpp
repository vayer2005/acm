#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; int m;
    cin >> n >> m;

    vector<vector<int>> vals;
    unordered_map<int, int> umap;

    for(int i =0; i < n; i++) {
        vector<int> temp = {};
        int tval;
        for (int j = 0;j < m; j++) {
            cin >> tval;
            temp.push_back(tval);
        }
        sort(temp.begin(), temp.end());
        vals.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        umap[vals[i][0]] = i+1;
        if (vals[i][0] >= n) {
            cout << -1 << endl;
            return;
        }
    }
    

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vals[j][i] < (((i+1) * n)) && (vals[j][i] == vals[j][i-1] + n)) {
                continue;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << umap[i] << " ";
    }
    cout << endl;



    
    

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}