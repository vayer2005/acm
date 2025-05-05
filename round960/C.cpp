#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;
const int N = 200005;

int a[N];
bool c[N];
int n;

void doit()
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[a[i]])
            maxu = max(maxu, a[i]);
        c[a[i]] = true;
        a[i] = maxu;
    }
}

void solve() {
    
    cin >> n;
    
    map<int,int> umap;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        ans += a[i];
    }
    doit();
    for(int i = 1; i <= n; i++) {
        ans += a[i];
    }
    doit();
    ll curr = 0;
    for(int i = 1; i <= n; i++) {
        curr += a[i];
        ans += curr;
    }

    cout << ans << endl;



    ll sum = 0;
    
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