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

    map<int, int> occur;
    
    for(int i = 0; i < n; i++) {
        occur[arr[i]] += 1;
    }

    int longestSub = 0;
    int lstart = -1;
    int ltemp;
    int length;

    int ind = 0;
    while (ind < n) {
        length = 0;
        ltemp = ind;
        while (ind < n && occur[arr[ind]] == 1) {
            length += 1;
            ind += 1;
        }
        if (length > longestSub) {
            longestSub = length;
            lstart = ltemp;
        }
        ind += 1;
    }

    if (lstart == -1) {
        cout << "0\n";
        return;
    }

    cout << lstart+1 << " " << lstart + longestSub << endl;




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