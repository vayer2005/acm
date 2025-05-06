#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;

vector<int> p, ip(6e6, 1);



void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    long long suma = 0, sump = 0;
    for (int i = 0; i < n; ++i) {
      suma += a[i];
      sump += p[i];
      if (suma >= sump) ans = i + 1;
    }
    cout << n - ans << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    

    for (int i = 2; i < 6e6; ++i) {
        if (!ip[i]) continue;
        p.push_back(i);
        for (int j = i; j < 6e6; j += i) {
            ip[j] = 0;
        }
    }

    while (t--) {
        solve();
    }

}