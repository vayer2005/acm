#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {

    int n;
    cin >> n;


    ll arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    unsigned long long cnt1 = 0;
    unsigned long long curr = 0;
    unsigned long long total = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            cnt1+=1;
        } else if (arr[i] == 2) {
            curr = (curr * 2 + cnt1) % 998244353;
        } else {
            total += curr;
            total %= 998244353;
        }
    }

    cout << total % 998244353<< endl;
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