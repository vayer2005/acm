#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ones = 0, twos = 0;
    vector<int> others;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) ones++;
        else if (a[i] == 2) twos++;
        else others.push_back(a[i]);
    }

    vector<vector<int>> groups;

    int pair12 = min(ones, twos);
    for (int i = 0; i < pair12; ++i) groups.push_back({1, 2});
    ones -= pair12;
    twos -= pair12;

    bool loneOnePending = false;
    if (ones >= 4 && ones % 3 == 1) {
        int cnt3 = (ones - 4) / 3;        
        for (int i = 0; i < cnt3; ++i) groups.push_back({1, 1, 1});
        groups.push_back({1, 1});         
        groups.push_back({1, 1});
        ones = 0;
    } else {
        int cnt3 = ones / 3;
        for (int i = 0; i < cnt3; ++i) groups.push_back({1, 1, 1});
        ones -= cnt3 * 3;
        if (ones == 2) {
            groups.push_back({1, 1});
            ones = 0;
        }
        else if (ones == 1) {
            if (!groups.empty()) groups[0].push_back(1);
            else loneOnePending = true;
            ones = 0;
        }
    }

    for (int i = 0; i < twos; ++i) groups.push_back({2});

    sort(others.begin(), others.end());
    bool firstOtherHandled=false;
    for (int val : others) {
        if (loneOnePending && !firstOtherHandled) {
            groups.push_back({val,1});
            loneOnePending=false;
            firstOtherHandled=true;
        } else {
            groups.push_back({val});
            firstOtherHandled=true;
        }
    }
    if(loneOnePending){
        groups.push_back({1});
    }

    for (size_t i = 0; i < groups.size(); ++i) {
        cout << "(";
        for (size_t j = 0; j < groups[i].size(); ++j) {
            if (j) cout << "+";
            cout << groups[i][j];
        }
        cout << ")";
        if (i + 1 < groups.size()) cout << "*";
    }
    cout << "\n";
    
    

	
}
