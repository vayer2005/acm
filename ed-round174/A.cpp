#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    int arr[n-2];
    for (int i = 0; i < n-2; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n-4; i++) {
        if (arr[i] == 1 && arr[i+1] == 0 && arr[i+2] == 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    return;
        


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