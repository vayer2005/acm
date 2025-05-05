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

    sort(arr, arr+n);
    
    int start;

    if (n%2 == 1) {
        start = 0;
    } else {
        start = 1;
    }

    for(int i = n-start; i>=0; i-=2) {
        if (i == 0) {
            cout << "YES\n";
            return;
        }
        if (arr[i] != arr[i-1]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

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