#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int num1s = 0;
    for(int i =0;i <s.length();i++){
        if (s[i] == '1') {
            num1s+=1;
        }
    }
    cout << num1s << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}