#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;


void solve() {
  ll n;
  cin >> n;

  set<pair<ll,ll>> edges;
  vector<ll> deg(n+1);

  for (int i = 0; i < n-1; i++) {
    ll a; ll b;
    cin >> a >> b;
    edges.insert(mp(a, b));
    edges.insert(mp(b,a));
    deg[a]++;
    deg[b]++;
  }

  ll ans = 0;
  vector<pair<ll,ll>> b;

  for (int i = 0; i < n; i++) {
    b.push_back(mp(deg[i+1], i+1));
  }

  for(auto x : edges) {
    ans = max(ans, deg[x.first] + deg[x.second] - 2);
  }

  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (edges.find(mp(b[i].second, b[j].second)) == edges.end()) {
            ans = max(ans, b[j].first + b[i].first - 1);
            break;
        } 
    }
  }

  cout << ans << endl;





\
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