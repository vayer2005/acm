#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> masks(n);
    vector<int> early(1<<20,-1);
    int all_ones = (1 << m) - 1;
    vector<int> dp(1<<20,0);
    int seen = false;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int mask = 0;
        reverse(s.begin(), s.end());
        for (int j = 0; j < m; j++) {
            if (s[j] == 'Y') mask |= (1 << j);
        }
        if (mask == all_ones) seen = true;
        masks[i] = mask;
        dp[mask] = mask;
        if (early[mask] == -1) {
            early[mask] = i;
        } 
    }


    if (seen) {
        int f = early[all_ones];
        int u = -1;
        int r = -1;
        for (int j = 0; j < n; j++) {
            if (j == f) continue;
            if (__builtin_popcount(all_ones & masks[j]) > r) {
                u = j;
                r = __builtin_popcount(all_ones & masks[j]);
            }
        }
        u+=1;
        f+=1;
        if (f > u) swap(f,u);
        cout << f << " " << u << endl;
        return 0;
    }
    

    for(int i = all_ones; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            int super = dp[i|(1 << j)];
            int ones = __builtin_popcount(super);
            if (ones > __builtin_popcount(dp[i]) || (dp[i] != 0 && ones == __builtin_popcount(dp[i]) && early[super] < early[dp[i]])) {
                dp[i] = super;
            }
        }
    }


    int i1 = -1; int i2= -1;
    int lap=-1;

    set<int> sen;
    for(int i = 0; i < n; i++) {
        int x = all_ones ^ masks[i];
        if (sen.find(x) != sen.end()) continue;
        sen.insert(x);

        int val = dp[x];
        
        if (val != 0) {
            int ovr = __builtin_popcount(masks[i] & val);
            if (lap < ovr) {
                i1 = early[masks[i]];
                i2 = early[val];
                lap = ovr;
            }
        }
    }

    if (i1 == -1 || i2 == -1) {
        cout << "No\n";
        return 0;
    }
    if (i1 > i2) swap(i1,i2);
    cout << i1 + 1 << " " << i2 + 1 << endl;
   
}