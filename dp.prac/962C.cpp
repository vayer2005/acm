#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int q;
    cin >> n >> q;

    int adp[26][n+1];
    int bdp[26][n+1];

    string a; string b;
    cin >> a >> b;

    vector<vector<int>> queries;
    for(int i = 0; i < q; i++) {
        vector<int> vals(2,0);
        cin >> vals[0] >> vals[1];
        queries.push_back(vals);
    }

    for(int i =0; i < 26; i++) {
        adp[i][0] = 0;
        bdp[i][0] = 0;
    }

    for(int j = 1; j < n+1; j++) {
        for(int i = 0; i < 26; i++ ){
            adp[i][j] = adp[i][j-1];
            bdp[i][j] = bdp[i][j-1];
            if ('a'+i == a[j-1]) {
                adp[i][j] += 1;
            }
            if ('a'+i == b[j-1]) {
                bdp[i][j] +=1;
            }      
        }
    }

    for(int i = 0; i < q; i++) {
        int l = queries[i][0]-1;
        int r = queries[i][1];
        int total = 0;
        for(int i = 0; i < 26;i++) {
            
            total += max(0, adp[i][r] - adp[i][l] - (bdp[i][r] - bdp[i][l]));
        }
        cout << total << endl;
    }
    /*

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < n+1; j++ ){ 
            cout << bdp[i][j] << " ";
        }
        cout << endl;
    }
    cout <<endl;

    */

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