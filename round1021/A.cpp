#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    string s;
    cin >> s;

    string res = "";

    map<char, int> mp;
    for(char x : s) {
        mp[x]++;
    }


    int val; char toAdd;
    for(int i = 0; i < 10; i++) {
        val = 9-i;
        
        while (mp['0' + val] == 0) {
            val++;
        }
        
        toAdd = '0' + val;
        res += toAdd;
        mp['0' + val]--;
    }

    cout << res << endl;
    

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