#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> occur(2000,0);

    for(int i = 0; i < n; i++) {
        occur[arr[i]] += 1;
    }


    for(int i = 0; i < 2000; i++) {
        if (occur[i] == 1) {
            cout << "NO\n";
            return;
        }
        if (occur[i] >= 2){
            int val = occur[i] - 2;
            occur[i] = 2;
            occur[i+1] = occur[i+1] + val;
        }
    }

    for(int i = 0; i < 2000; i++) {
        if (occur[i] % 2 != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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