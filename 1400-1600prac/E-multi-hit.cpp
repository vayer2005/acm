#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
    int k;
    cin >> k;

    int base = k;
    int x = 0; int y = 0;
    vector<pair<int,int>> points;
    
    while (base != 0) {
        //Binary search for num .'s to add
        int l = 0; int r = 500;

        while (l <= r) {
            int mid = (l+r)/2;
            int val = (mid * (mid-1))/2;

            if (val > base) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        for (int i = 0; i < r; i++) {
            points.push_back({x, y});
            x+=1;
        }
        base -= (r * (r-1))/2;
        y+=1;
    }

    cout << points.size() << endl;

    for (auto pair : points) {
        cout << pair.first << "  " << pair.second << endl;
    }


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