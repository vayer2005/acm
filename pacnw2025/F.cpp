#include <bits/stdc++.h>

using namespace std;

#define int long long


int n, q;

signed main() { 
    cin >> n >> q;
    int lvl[n+1][51];
    map<int, vector<int>> adj;
    memset(lvl, 0, sizeof(lvl));
    vector<int> ntoys(n+1, 0);
    vector<int> tot(51, 0);
    
    tot[0] = n;
    char t;
    int i, j;
    
    for (int i = 1; i <= n; i++) {
        lvl[i][0] = 1;
    }

    while(q--) {
        cin >> t;
        if (t == 'F') {
            cin >> i >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);

            lvl[i][ntoys[j]]+=1;
            lvl[j][ntoys[i]]+=1;

        } else if (t == 'A') {
            cin >> i;
            int prev = ntoys[i];
            ntoys[i] += 1;
            int curr = ntoys[i];
            tot[prev]-=1;
            tot[curr]+=1;
            for (int x : adj[i]) {
                lvl[x][prev] -=1;
                lvl[x][curr] += 1;
            }
            lvl[i][prev]--;
            lvl[i][curr]++;
        } else {
            cin >> j;
            int fin = -1;
            for (int k = 50; k >= 0; k--) {
                if (lvl[j][k] < tot[k]) {
                    fin = k;
                    break;
                }
            }

            cout << fin << endl;
        }
    }
}