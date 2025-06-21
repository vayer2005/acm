#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


int main() {
    
    int n; cin >> n;

    ll a[n];
    map<ll,int> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x[a[i]] = i;
    }

    ll left[n];
    ll right[n];
    left[0] = -1;

    stack<ll> q;
    q.push(a[0]);
    
    for (int i = 1; i < n; i++) {
        while (!q.empty() && q.top() < a[i]) {
            q.pop();
        }
        if (q.empty()) left[i] = -1;
        else left[i] = q.top();
        q.push(a[i]);
    }

    right[n-1] = -1;
    stack<ll> q2;
    q2.push(a[n-1]);
    for (int i = n-2; i >= 0; i--) {
        while (!q2.empty() && q2.top() < a[i]) {
            q2.pop();
        }
        if (q2.empty()) right[i] = -1;
        else right[i] = q2.top();
        q2.push(a[i]);
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (left[i] == -1 && right[i] == -1) continue;
        else if (left[i] == -1) {
            ans += abs(i -x[right[i]]);
        } else if (right[i] == -1) {
            ans += abs(i-x[left[i]]);
        } else {
            ans += min(abs(i-x[left[i]]), abs(i-x[right[i]]));
        }
    }


    cout << ans << endl;
}


