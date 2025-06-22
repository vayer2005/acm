#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    string s, t;
    cin >> s >> t;

    vector<int> sa(26,0);
    vector<int> ta(26,0);

    for (int i = 1; i < s.size(); i++) {
        int c = s[i]-'a';
        if (sa[c] == 0) {
            sa[c] = i;
        }
    }

     for (int i = t.size()-2; i >= 0; i--) {
        int c = t[i]-'a';
        if (ta[c] == 0) {
            ta[c] = t.size()-i;
        }
    }

    int ans = 1e9;
    string a;
    for (int i = 0; i < 26; i++) {
        if (sa[i] != 0 && ta[i] != 0) {
            if (sa[i] + ta[i] < ans) {
                ans = sa[i] + ta[i];
                a = s.substr(0, sa[i]) + t.substr(t.size()-ta[i], ta[i]);
            }
        }
    }
    if (ans == 1e9) {
        cout << "-1\n";
        return 0;
    }
    cout << a << endl;



}   