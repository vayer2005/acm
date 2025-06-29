#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


signed main() {
    int n;
    cin >> n;
    ll start;
    cin >> start;
    ll v;
    for(int i = 0; i<n-1; i++) {
        cin >> v;
        start += v;
    }
    cout << start << endl;


}