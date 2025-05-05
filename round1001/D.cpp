#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<int,int>umap;

bool dfs(int val) {
    if (umap.find(val) != umap.end()) {
        if (umap[val] > 0) {
            umap[val]-=1;
            return true;
        }
    }
    if (val==1) {
        return false;
    }
    if (val%2==0) {
        return dfs(val/2) && dfs(val/2);
    } else {
        return dfs(val/2) && dfs((val/2)+1);
    }
}

void solve() {
    umap.clear();
    int n; int m; ll suma = 0; ll sumb = 0;
    cin >> n >> m;
    int a[n];
    
    for (int i=0; i < n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    
    int b[m];
    
    for (int i=0; i < m; i++) {
        cin >> b[i];
        sumb += b[i];
    }

    if (suma != sumb) {
        cout << "No\n";
        return;
    }
    
    for (int i = 0; i < n; i++) {
        umap[a[i]]+=1;
    }

    for (int i = 0; i < m; i++) {
        if (!dfs(b[i])) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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