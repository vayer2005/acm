#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n; int k; string s;

    cin >> n >> k >> s;

    ll arr[n];

    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll l = 0;
    ll r = 1e9;

    while (l < r) {
        //cout << l << " " << r << endl;
        ll mid = (l + r) / 2;

        string temp = "";
        for(int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                temp += s[i];
            }

        }

        int ind = 0;
        int kt = 0;
        while (ind < temp.size()) {
            if (ind == 0) {
                if (temp[ind] == 'B') {
                    kt+=1;
                }
            } else if (temp[ind-1] == 'R' && temp[ind] == 'B') {
                kt+= 1;                
                
            }
            ind +=1;
        }

        if (kt > k) {
            l = mid+1;
        } else {
            r =  mid;
        }
    }

    cout << r << endl;


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