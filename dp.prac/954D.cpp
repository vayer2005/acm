#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

int n; string s;

int helper(int ind, int smallest) {

    int start = 1;
    int res = stoi(s.substr(0,1));
    if (ind == 0) {
        start = 2;
        res = stoi(s.substr(0,2));
    }
    if (res == 0) {
        return 0;
    }
    int i = start;
    //cout << "NEW\n";
    while(i < n) {
        //cout << i << " " << res << endl;
        if (i != ind) {
            int num = stoi(s.substr(i,1));
            if (num == 0) {
                return 0;
            }
            if (res == 1) {
                res *= num;
            } else if (num != 1){
                res += num;
            }
            i+=1;
        } else {
            int num = smallest;
            if (num == 0) {
                return 0;
            }
            if (res == 1) {
                res *= num;
            } else if (num != 1) {
                res += num;
            }
            i+=2;
        }
    }

    return res;
}


void solve() {
    
    cin >> n; cin >> s;
    if (n == 2) {
        cout << stoi(s.substr(0,2)) << endl;
        return;
    }

    int result = 1e9;
    for(int i = 0; i < n-1; i++) {
        int val = stoi(s.substr(i,2));
        result = min(result, helper(i, val));
    } 
    cout << result << endl;

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