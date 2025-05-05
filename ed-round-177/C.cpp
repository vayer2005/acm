#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int n;
    cin >> n;

    int arr[n];
    int q[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    int nvisited = 0;
    set<int> visited;

    for (int val : q) {
        int num = val;
        while (visited.find(num) == visited.end()) {
            nvisited+=1;
            visited.insert(num);
            num = arr[num-1];
        }
        cout << nvisited << " ";
    }
    cout << endl;
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