#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n; int q;
    cin >> n >> q;
    ll arr[n];
    ll queries[q];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    
    unordered_map<ll, ll> sol;
    ll prev = n-1;
    ll subt = 0;
    for(int i = 0; i < n; i++) {

        ll diff = arr[i+1] - arr[i];
        ll curr = (ll)i * (n - i) + (ll)(n - i - 1);
        ll curr2 = (ll)i * (n - i - 1) + (ll)(n - i-1);
        if (sol.find(curr) == sol.end()) {
            sol[curr] = 0;
        }
        if (sol.find(curr2) == sol.end()) {
            sol[curr2] = 0;
        }
        sol[curr] += 1;
        sol[curr2] += diff-1;
        
    }

    for(int i =0; i < q; i++) {
        cout << sol[queries[i]] << " ";
    }

    cout << endl;
    

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}