#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


signed main() {
    string s;
    cin >> s;

    vector<int> seen(26,0);
    int nums = 0;
    for (int i = 0; i<s.size(); i++) {
        char c = s[i];
        if (seen[c-'A'] == 0) {
            seen[c-'A'] = 1;
            nums++;
        }
        if (s.size() - i - 1 == nums) {
            cout << i+1 << endl;
            return 0;
        }
    }
}