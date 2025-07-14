#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> res;
    string names[n];

    string c; int p; 
    for (int i = 0; i < n; i++) {
        cin >> c >> p;
        vector<int> tramp(6,0);
        for (int j=0;j<6;j++){
            cin >> tramp[j];
        }

        sort(tramp.begin(), tramp.end());
        names[i] = c;

        int score=0;

        score+=p*10;
        score+=tramp[1] + tramp[2] + tramp[3] + tramp[4];

        res.push_back({score, -1*i});
    }

    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());


    int finInd = n-1;
    int base = 0;
    for (int i = 1; i < n; i++) {
       
        if (res[i-1][0] > res[i][0]) {
            //prev > curr
            base = i;
        }
        //cout << i << " " << base << endl;
        if (base > 2) {
            finInd = i-1;
            break;
        }
        if (i > finInd) {
            break;
        }
    }
    for (int i = 0; i <= finInd; i++) {
        cout << names[-1*res[i][1]] << " " << res[i][0] << endl;
    }

}