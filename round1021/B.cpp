#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i =0;i<n;i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    set<int> s;

    for(int i = 0; i < n; i++) {
        if (abs(i-(n-i-1)) <= k+1) {
            s.insert(arr[i]);
        }
    }


    cout << *s.rbegin()-*s.begin() +1<< endl;
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