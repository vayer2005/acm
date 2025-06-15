#include <bits/stdc++.h>


typedef long long ll;
using namespace std;


int main() {
    int n;
    ll m; cin >> n >> m;

    vector<pair<ll,ll>> arr;

    ll a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr.push_back({a,b});
    }

    sort(arr.begin(), arr.end());

    priority_queue<ll, vector<ll>, greater<ll>> minHeap;

    int locks = 0;

    for (auto x : arr) {
        ll come = x.first;
        ll stay = x.second;
        while (!minHeap.empty() && minHeap.top() < come) {
            minHeap.pop();
        }
        
        if (minHeap.empty()) {
            locks++;
        } else {
           ll riv = minHeap.top();
            minHeap.pop();
            if (riv-m > come) {
                locks++;
                minHeap.push(riv);
            }
        }

        minHeap.push(come + stay + m);

    }

    cout << n - locks << endl;

}