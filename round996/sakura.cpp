#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



void solve() {
    int n; 
    cin >> n;
    int nums[n];
    string s;
    vector<int> solution(n, -1);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] -= 1;
    }
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (solution[i] != -1) {
            continue;
        }
        vector<int> changes;
        changes.push_back(i);

        int total = 0;
        if (s[i] == '0') {
            total += 1;
        }
        int curr = nums[i];

        while (curr != i) {
            changes.push_back(curr);
            if (solution[curr] != -1) {
                total = solution[curr];
                break;
            }
            if (s[curr] == '0') {
                total += 1;
            }
            curr = nums[curr];
        }

        for (int j = 0; j < changes.size(); j++) {
            solution[changes[j]] = total;
        }
        changes.clear();
    }

    for(int i = 0; i < n; i++) {
        cout << solution[i] << " ";
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