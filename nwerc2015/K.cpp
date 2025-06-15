#include <bits/stdc++.h>
 
 
typedef long long ll;
using namespace std;
int r,n; ll s, m, d;
vector<ll> dishes[76];
ll ing[1001];
map<ll, set<ll>> banned;
ll sol = 0;
 
void dfs(int smd, vector<ll> usedDishes, set<ll> usedIngs) {
    if (sol > 1e18) {
        return;
    }
    if (smd == 1) {
        for (int i = 1; i <= s; i++) { // loop through starters
            set<ll> added;
            for (ll x : dishes[i]) { // through ingredients in dish
                added.insert(x);
            }
            dfs(2, {i}, added);
        }
    } else if (smd == 2) {
        ll used = usedDishes[0];
        for (int i = s+1; i<= m+s; i++) {
            set<ll> added = usedIngs;
            if (banned[i].find(used) == banned[i].end()) {
                for (ll x : dishes[i]) {
                    if (usedIngs.find(x) == usedIngs.end()) {
                        added.insert(x);
                    } 
                }
                dfs(3, {used, i}, added);
            }
        }
    } else {
        ll used1 = usedDishes[0];
        ll used2 = usedDishes[1];
 
        for (int i = s + m + 1; i <= s + m + d; i++) {
            set<ll> added = usedIngs;
            if (banned[i].find(used1) == banned[i].end() && banned[i].find(used2) == banned[i].end()) {
                for (ll x : dishes[i]) {
                    if (usedIngs.find(x) == usedIngs.end()) {
                        added.insert(x);
                    }
                }
 
                if (sol > 1e18) return;
                ll temp = 1;
                for (ll x : added) {
                    if (1e18/ing[x] < temp) {
                        sol = 1e18 + 100;
                        return;
                    }
                    temp *= ing[x];
                }

                if (1e18 - sol < temp) {
                    sol = 1e18 + 100;
                    return;
                } 
                sol += temp;   
            }
        }
    }
}
 
 
int main() {
    cin >> r >> s >> m >> d >> n;
 
    for (int i = 1; i <= r; i++) {
        cin >> ing[i];
    }
    int k; ll x;
 
    for (int i = 1; i <= s; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            dishes[i].push_back(x);
        }
    }
 
    for (int i = s + 1; i <= s + m; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            dishes[i].push_back(x);
        }
    }
 
    for (int i = s + m + 1; i <= s + m + d; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> x;
            dishes[i].push_back(x);
        }
    }
 
    ll u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        banned[u].insert(v);
        banned[v].insert(u);
    }
 
 
    dfs(1, {}, {});
 
    if (sol > 1e18) {
        cout << "too many\n";
    }else { 
        cout << sol << endl;
    }
    
    
 
}
